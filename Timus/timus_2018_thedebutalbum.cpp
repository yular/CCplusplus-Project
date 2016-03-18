/*
 *
 * Tag: DP
 * Time: O(n*max(a, b))
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
const int N = 51000;
const int M = 310;
const long long MOD = 1000000007;
const double eps = 1e-10;
int dp[2][N];
int n, a, b;

int main() {
    scanf("%d%d%d",&n,&a,&b);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= min(a, i); ++ j) {
            dp[0][i] += dp[1][i - j];
            dp[0][i] %= MOD;
        }
        for (int j = 1; j <= min(b, i); ++ j) {
            dp[1][i] += dp[0][i - j];
            dp[1][i] %= MOD;
        }
    }
    int ans = (dp[0][n] + dp[1][n])%MOD;
    printf("%d\n", ans);
    return 0;
}
