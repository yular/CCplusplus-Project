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
int sums, sumq;

int main() {
    scanf("%d",&n);
    sums = sumq = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&s[i]);
        sums += s[i];
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d",&q[i]);
        sumq += q[i];
    }
    bool isfirst = true;
    if (sumq < sums) {
        for (int i = 0; i < n; ++ i) {
            if (!isfirst) {
                printf(" ");
            }
            printf("%d",s[i]);
            isfirst = false;
        }
    } else {
        for (int i = 0; i < m; ++ i) {
            if (!isfirst) {
                printf(" ");
            }
            printf("%d",q[i]);
            isfirst = false;
        }
    }
    puts("");
    return 0;
}
