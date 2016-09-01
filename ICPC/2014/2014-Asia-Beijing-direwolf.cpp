/*
*
* Tag: DP
* Time: O(n^3)
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
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 300;
const int M = 100100;
const long long MOD = 1000000007;
const double eps = 1e-10;
const double pi = acos(-1.0);
int dp[N][N], a[N], b[N];
int n;


int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        scanf("%d",&n);
        for (int i = 1; i <= n; ++ i)
            scanf("%d",&a[i]);
        for (int i = 1; i <= n; ++ i)
            scanf("%d",&b[i]);
        b[0] = b[n + 1] = 0;
        for (int i = 1; i <= n; ++ i) {
            dp[i][i] = a[i] + b[i - 1] + b[i + 1];
        }
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j + i <= n; ++ j) {
                dp[j][j + i] = INT_MAX;
                for (int k = j; k <= j + i; ++ k) {
                    if (k == j) {
                        dp[j][j + i] = min(dp[j][j + i], dp[k + 1][j + i] + a[k] + b[k - 1] + b[j + i + 1]);
                    } else if (k == j + i) {
                        dp[j][j + i] = min(dp[j][j + i], dp[j][k - 1] + a[k] + b[j - 1] + b[k + 1]);
                    } else {
                        dp[j][j + i] = min(dp[j][j + i], dp[j][k - 1] + dp[k + 1][j + i] + a[k] + b[j - 1] + b[j + i + 1]);
                    }
                }
            }
        }
        printf("Case #%d: %d\n",cas,dp[1][n]);
    }
    return 0;
}
