/*
 *
 * Tag: Implementation
 * Time: O(nx)
 * Space: O(n)
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 310;
const int M = 101010;
const double eps = 1e-10;
int n, x;
int s[N], q[N];

int main() {
    scanf("%d%d",&n,&x);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&s[i]);
    }
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&q[i]);
    }
    bool isfirst = true;
    for (int i = 0; i < n; ++ i) {
        bool isfind = false;
        for (int j = i; j >= max(0, i - x); -- j) {
            if (s[i] == q[j]) {
                isfind = true;
                break;
            }
        }
        for (int j = i; j <= min(n - 1, i + x); ++ j) {
            if (s[i] == q[j]) {
                isfind = true;
                break;
            }
        }
        if (isfind) {
            if (!isfirst) {
                printf(" ");
            }
            printf("%d",i + 1);
            isfirst = false;
        }
    }
    puts("");
    return 0;
}
