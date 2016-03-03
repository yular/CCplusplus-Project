/*
 *
 * Tag: DP
 * Time: O(n^n)
 * Space: O(n^n)
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
const int N = 20;
const int M = 130;
const double eps = 1e-10;
long long dp[N][N];
int n;

void init(){
    memset(dp, 0, sizeof(dp));
}

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        init();
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++ i) {
            dp[0][i] = 1;
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        printf("%lld\n",dp[n][n]);
    }
    return 0;
}
