/*
*
* Tag: DP
* Time: O(n*(1<<20))
* Space: O(1<<20)
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
const int N = 1048576;
const int M = 3000;
const long long MOD = 1000000007;
const double eps = 1e-10;
const double pi = acos(-1.0);
long long dp[2][N];
int n, m, v, a;

int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d",&n,&m);
        long long ans = 0;
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++ i) {
            scanf("%d",&v);
            for (int j = 0; j < N; ++ j) {
                dp[(i%2)][j] = dp[(i - 1)%2][j] + dp[(i - 1)%2][j^v];
            }
        }
        for (int i = m; i < N; ++ i) {
            ans += dp[n%2][i];
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}
