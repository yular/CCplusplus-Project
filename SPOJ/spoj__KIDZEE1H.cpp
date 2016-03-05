/*
 *
 * Tag: Implementation
 * Time: O(n^2)
 * Space: O(1)
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
const int N = 3000200;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
int n, m;

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n, &m);
        printf("Case %d: \n", cas++);
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= i; ++ j) {
                printf("%d",n);
            }
            puts("");
        }
    }
    return 0;
}
