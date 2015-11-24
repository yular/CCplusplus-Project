/*
*
* Tag: DFS
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
#include<queue>
#include<set>
#include<bitset>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
const int MOD = 9901;
const int INF = 1<<29;
const double ITF = 1e40;
const int N = 130;
const int M = 1000100;
int n, s;
int len[N], raw[N][2][10];
short side[N][N];
bool vis[N];
int ans, sta;

void build(){
    for(int i = 1; i <= n; ++ i){
        scanf("%d",&s);
        int u, v;
        scanf("%d%d%d",&len[s],&u,&v);
        for(int j = 0; j < u; ++ j){
            scanf("%d",&raw[s][0][j]);
            side[s][raw[s][0][j]] = 0;
        }
        for(int j = 0; j < v; ++ j){
            scanf("%d",&raw[s][1][j]);
            side[s][raw[s][1][j]] = 1;
        }
    }
}

void dfs(int cur,int p,int s){
    if(p >= ans)
        return;

    if(cur == sta && p != 0){
        ans = p;
        return ;
    }

    for(int i = 0; i < 8 && raw[cur][s][i] != 0; ++ i){
        if(!vis[raw[cur][s][i]]){
            vis[raw[cur][s][i]] = 1;
            dfs(raw[cur][s][i],p + len[cur],1 - side[raw[cur][s][i]][cur]);
            vis[raw[cur][s][i]] = 0;
        }
    }
}

void solve(){
    ans = INT_MAX;
    for(sta = 1; sta <= n; ++ sta){
        memset(vis,0,sizeof(vis));
        dfs(sta,0,0);
    }
}

int main(){
    freopen("fence6.in","r",stdin);
    freopen("fence6.out","w",stdout);
    scanf("%d",&n);
    build();
    solve();
    printf("%d\n",ans);
    return 0;
}
