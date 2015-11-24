/*
*
* Tag: Graph Theory (Max Match)
* Time: O(nm)
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
const int M = 300;
int n, m, ans;
bool mp[M][M];
int result[M];
bool vis[M];

void build(){
    memset(vis, 0, sizeof(vis));
    memset(result,0,sizeof(result));
    ans = 0;
    for(int i = 1; i <= n; ++ i){
        int t,k,v;
		scanf("%d",&t);
		while(t --){
            scanf("%d",&v);
            mp[i][v] = 1;
		}
    }
}

bool findMatch(int u){
    for(int i = 1; i <= m; ++ i){
		if(mp[u][i] && !vis[i]){
			vis[i]=true;
			if(result[i] == 0 || findMatch(result[i])){
				result[i] = u;
				return true;
			}
		}
	}
	return false;
}

void solve(){
    for(int i = 1; i <= n; ++ i){
			memset(vis,0,sizeof(vis));
			if(findMatch(i))
                ++ ans;
    }
}

int main(){
    freopen("stall4.in","r",stdin);
    freopen("stall4.out","w",stdout);
    scanf("%d%d",&n,&m);
    build();
    solve();
    printf("%d\n",ans);
    return 0;
}
