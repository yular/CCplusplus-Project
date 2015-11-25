/*
*
* Tag: DFS
* Time: O(V^2)
* Space: O(V^2)
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
int n;
vector<vector<int> > mp(N);
bool asmp[N][N];
int s, t;
set<int> ans1, ans2;
bool vis[N], isfind;
int chk[N];

void dfs(int u){
    for(int i = 0; i < mp[u].size(); ++ i){
        int v = mp[u][i];
        if(!vis[v]){
            vis[v] = 1;
            if(v == n)
                return ;
            dfs(v);
        }
    }
}

void dfssp(int u){
    for(int i = 0; i < mp[u].size(); ++ i){
        int v = mp[u][i];
        if(!chk[v]){
            chk[v] = 1;
            dfssp(v);
        }
    }
}

void dfsst(int u, int st){
    for(int i = 0; i < mp[u].size(); ++ i){
        int v = mp[u][i];
        if(!chk[v]){
            chk[v] = 2;
            dfsst(v, st);
            if(isfind)
                return ;
        }else if(chk[v] == 1 && v != st){
            isfind = true;
            return ;
        }
    }
}

int main(){
    freopen("race3.in","r",stdin);
    freopen("race3.out","w",stdout);
    int cur = 0, v;
    n = 0;
    while(scanf("%d",&v) == 1 && v != -1){
        while(v != -2){
            mp[cur].push_back(v);
            scanf("%d",&v);
        }
        ++ cur;
    }
    n = cur - 1;

    for(int i = 1; i < n; ++ i){
        vis[i] = 1;
        dfs(0);
        if(!vis[n]){
            ans1.insert(i);
        }
        memset(vis, 0, sizeof(vis));
    }
    set<int>::iterator it = ans1.begin();
    printf("%d", ans1.size());
    for(; it != ans1.end(); ++ it){
        printf(" %d", *it);
    }
    puts("");
    it = ans1.begin();
    for(; it != ans1.end(); ++ it){
        memset(chk, 0, sizeof(chk));
        chk[*it] = 1;
        isfind = false;
        dfssp(*it);

        if(!chk[0]){
            chk[0] = 2;
            dfsst(0, *it);
        }else
            isfind = true;
        if(!isfind){
            ans2.insert(*it);
        }
    }
    it = ans2.begin();
    printf("%d", ans2.size());
    for(; it != ans2.end(); ++ it){
        printf(" %d", *it);
    }
    puts("");
    return 0;
}
