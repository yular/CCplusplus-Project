/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
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
//#include<queue>
#include<set>
#include<bitset>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
const int MOD = 9901;
const int INF = 1<<29;
const double ITF = 1e40;
const int N = 10010;
const int M = 1200;
const int LIM = 1000000000;
const double eps=1e-8;
int n, t;
bool mp[M][M];
int dp[M][M];

inline int minval(int a, int b, int c){
    if(a <= b && a <= c)
        return a;
    if(b <= a && b <= c)
        return b;
    return c;
}

int main(){
    freopen("bigbrn.in","r",stdin);
    freopen("bigbrn.out","w",stdout);
    scanf("%d%d",&n,&t);
    memset(mp, 0, sizeof(mp));
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < t; ++ i){
        int u, v;
        scanf("%d%d",&u,&v);
        mp[u][v] = 1;
    }
    if(n*n == t){
        printf("%d\n",ans);
    }else{
        ++ ans;
        for (int i = 1; i <= n; ++ i){
            if (!mp[n][i])
                dp[n][i] = 1;
            else
                dp[n][i] = 0;
            if (!mp[i][n])
                dp[i][n] = 1;
            else
                dp[i][n] = 0;
        }

        for(int i = n - 1; i >= 1; -- i){
            for(int j = n - 1; j >= 1; -- j){
                if(mp[i][j])
                    dp[i][j] = 0;
                else{
                    dp[i][j] = minval(dp[i + 1][j], dp[i + 1][j + 1], dp[i][j + 1]) + 1;
                    ans = max(dp[i][j], ans);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
