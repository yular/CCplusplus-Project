/*
*
* Tag: DP
* Time: O(tmn^2)
* Space: O(mn)
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include <ctype.h>
#include<fstream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<bitset>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
const int MOD = 9901;
const int INF = 1<<29;
const double ITF = 1e40;
const int N = 30;
const int M = 1010;
int dp[N][N], song[N], tmpdp[N];
int n, t, m;

int main(){
    freopen("rockers.in","r",stdin);
    freopen("rockers.out","w",stdout);
    memset(dp, 0, sizeof(dp));
    memset(tmpdp, 0, sizeof(tmpdp));
    cin>>n>>t>>m;
    for(int i = 1; i <= n; ++ i)
        cin>>song[i];
    for(int k = 1; k <= m; ++ k){
        for(int l = k; l <= n; ++ l){
            memset(tmpdp, 0, sizeof(tmpdp));
            for(int i = l; i<= n; ++ i){
                for(int j = t; j >= song[i]; -- j){
                    tmpdp[j] = tmpdp[j - song[i]] + 1;
                }
                dp[k][i] = max(dp[k][i], dp[k - 1][l - 1] + tmpdp[t]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; ++ i)
        ans = max(ans, dp[i][n]);
    cout<<ans<<endl;
    return 0;
}
