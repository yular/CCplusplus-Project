/*
*
* Tag: Graph Theory
* Time: O(VE)
* Space: O(V^2)
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
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
//const int N = 5100;
const int M = 510;
ifstream fin("fence.in");
ofstream fout("fence.out");
int mp[M][M], deg[M];
stack<int> st, ans;
int f;

int getNext(int u){
    for(int i = 1; i < 501; ++ i){
        if(mp[u][i])
            return i;
    }
    return 0;
}

int main(){
    fin>>f;
    memset(mp, 0, sizeof(mp));
    memset(deg, 0, sizeof(deg));
    int a, b;
    int sta = M;
    for(int i = 0; i < f; ++ i){
        fin>>a>>b;
        sta = min(sta, min(a, b));
        ++ mp[a][b];
        ++ mp[b][a];
        ++ deg[a];
        ++ deg[b];
    }
    for(int i = 1; i < 501; ++ i){
        if(deg[i]%2 == 1){
            sta = i;
            break;
        }
    }
    st.push(sta);
    while(!st.empty()){
        int u = st.top();
        if(!deg[u]){
            ans.push(u);
            st.pop();
        }
        while(deg[u]){
            int v = getNext(u);
            -- deg[u];
            -- deg[v];
            -- mp[u][v];
            -- mp[v][u];
            u = v;
            st.push(v);
        }
    }
    while(!ans.empty()){
        fout<<ans.top()<<endl;
        ans.pop();
    }
    return 0;
}
