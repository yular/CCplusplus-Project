/*
 *
 * Tag: Implementation
 * Time: O(n)
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
int n, m;
int s[N], q[N];

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&s[i]);
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d",&q[i]);
    }
    bool isfirst = true;
    for (int i = 0; i < min(n, m); ++ i) {
        if (s[i] == q[i]) {
            if (!isfirst) {
                printf(" ");
            }
            printf("%d", i+1);
            isfirst = false;
        }
    }
    puts("");
    return 0;
}
