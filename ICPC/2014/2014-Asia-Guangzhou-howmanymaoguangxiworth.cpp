/*
*
* Tag: Graph
* Time: O(n^4)
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
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 50;
const int M = 50000010;
const long long MOD = 1000000007;
int mp[N][N], dp[N][N];
int n, m, s, t, u, v, w, ans;

void solve(int x){
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (i == x || j == x) {
                dp[i][j] = M;
            } else {
                dp[i][j] = mp[i][j];
            }
        }
    }
    
    for (int k = 1; k <= n; ++ k) {
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main(){
    while (scanf("%d%d",&n,&m) == 2) {
        if(!n && !m)
            break;
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                mp[i][j] = i==j?0:M;
            }
        }
        ans = 0;
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d%d",&u,&v,&w);
            mp[u][v] = mp[v][u] = min(mp[u][v], w);
        }
        for (int i = 2; i < n; ++ i) {
            solve(i);
            ans = max(ans, dp[1][n]);
            if (ans >= M) {
                break;
            }
        }
        if (ans >= M) {
            puts("Inf");
        } else {
            printf("%d\n",ans);
        }
    }
    return 0;
}
