/*
 *
 * Tag: DP
 * Time: O(n^2)
 * Space: O(n^2)
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
const int N = 110;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
int dp[N][N], a[N][N];
int n,c;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&c);
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                scanf("%d",&a[i][j]);
            }
        }
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }
        if (dp[n][n] >= c) {
            printf("%d\n",dp[n][n] - c);
        } else {
            puts("-1");
        }
    }
    return 0;
}
