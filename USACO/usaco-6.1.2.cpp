/*
*
* Tag: DP
* Time: O(rc)
* Space: O(r+c)
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
const int N = 25;
const int M = 3002;
const int LIM = 1000000000;
const double eps=1e-8;
int r, c, p, ans;
bool mp[M][M];
int h[M], l[M], rw[M];

inline int min(int a, int b){
    if(a < b && a)
        return a;
    return b;
}

void work(){
    for(int i = 1; i <= r; ++ i){
        int k = 0;
        for(int j = 1; j <= c; ++ j){
            if(!mp[i][j]){
                ++ h[j];
                l[j] = min(l[j], ++ k);
            }else{
                l[j] = 0;
                k = 0;
                h[j] = 0;
            }
        }

        k = 0;
        for(int j = c; j >= 1; -- j){
            if(!mp[i][j]){
                rw[j] = min(rw[j], ++ k);
                ans = max(ans, h[j]*(l[j] + rw[j] - 1));
            }else{
                k = 0;
                rw[j] = 0;
            }
        }
    }
}

int main(){
    freopen("rectbarn.in","r",stdin);
    freopen("rectbarn.out","w",stdout);
    scanf("%d%d%d",&r,&c,&p);
    memset(mp, 0, sizeof(mp));
    memset(l, 0, sizeof(l));
    memset(rw, 0, sizeof(rw));
    ans = 0;
    for(int i = 0; i < p; ++ i){
        int u, v;
        scanf("%d%d",&u,&v);
        mp[u][v] = 1;
    }
    work();
/*
    for(int i = 1; i <= r; ++ i){
        for(int j = 1; j <= c; ++ j){
            printf("%d ",dp[i][j]);
        }
        puts("");
    }
*/
    printf("%d\n",ans);
    return 0;
}
