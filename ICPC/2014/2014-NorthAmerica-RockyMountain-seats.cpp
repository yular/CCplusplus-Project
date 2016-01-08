/*
*
* Tag: DP
* WA
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<climits>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#include<cmath>
#include<list>
#include<sstream>
#include<time.h>
using namespace std;
const int M = 60;
const int N = 500;
const double eps = 1e-8;
const double dinf = 1e15;
const int MOD = 100000007;
int n, w, k;
int airline[M][N][2];
int plancnt[M];
int dp[N], tmpdp[N], setdp[N];

int main(){
 //   freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&w) == 2){
        for(int i = 0; i <= w; ++ i){
            scanf("%d",&plancnt[i]);
            for(int j = 0; j < plancnt[i]; ++ j){
                scanf("%d",&airline[i][j][0]);
            }
            for(int j = 0; j < plancnt[i]; ++ j){
                scanf("%d",&airline[i][j][1]);
            }
        }
        int ans = 0, price = 1<<29, ubnd;
        for(int i = 0; i < plancnt[0]; ++ i){
            memset(dp,0, sizeof(dp));
            if(airline[0][i][1] <= n)
                dp[airline[0][i][1]] = airline[0][i][1]*airline[0][i][0];
            else
                dp[n] = airline[0][i][1]*airline[0][i][0];
            ubnd = airline[0][i][1];
            for(int j = 1; j <= w; ++ j){
                memset(tmpdp, 0, sizeof(tmpdp));
                for(int l = 0; l < plancnt[j]; ++ l){
                    for(int k = n + airline[j][l][1] - 1; k >= ubnd + airline[j][l][1]; -- k){
                        if(!dp[k - airline[j][l][1]])
                            continue;
                        if(k < n)
                            tmpdp[k] = max(tmpdp[k], dp[k - airline[j][l][1]] + airline[j][l][1]*airline[j][l][0]);
                        else
                            tmpdp[n] = max(tmpdp[n], dp[k - airline[j][l][1]] + (airline[j][l][1] - (k - n))*airline[j][l][0]);
                    }
                }

                for(int l = 1; l <= n; ++ l){
                    dp[l] = max(dp[l], tmpdp[l]);
                    if(dp[l])
                        ubnd = l;
                //    printf("%d ",dp[l]);
                }
            //    printf("ubd = %d\n",ubnd);
            //    puts("");
            }
            int tmpans = 0;
            for(int j = 1; j <= n; ++ j){
                tmpans = max(tmpans, dp[j]);
            }
            if(tmpans > ans){
                ans = tmpans;
                price = airline[0][i][0];
            }else if(tmpans == ans){
                price = min(price, airline[0][i][0]);
            }
        }
        printf("%d\n%d\n",ans,price);
    }
    return 0;
}
