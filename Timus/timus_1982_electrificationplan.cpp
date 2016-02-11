/*
*
* Tag: Graph (MST, Kruskal)
* Time: O(ElgE)
* Space: O(E + V)
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
const int N = 300;
const int M = 12011;
const int MOD = 10037;
const double dinf = 1e20;
const double eps = 1e-6;
struct edge{
    int u, v, w;
    bool operator < (const edge a)const{
        return w < a.w;
    }
}e[M];
int n, k, m, tot;
int pos[N], ans, fa[N];
int mp[N][N];

void init(){
    m = 2;
    memset(pos, 0, sizeof(pos));
    for (int i = 1; i <= n; ++ i) {
        fa[i] = -1;
    }
    tot = 0;
}

int findfa(int u){
    int s = u;
    for (; fa[s] >= 0; s = fa[s]) ;
    while (u != s) {
        int tmp = fa[u];
        fa[u] = s;
        u = tmp;
    }
    return s;
}

void unionedge(int u, int v){
    int fu = findfa(u), fv = findfa(v);
    int tmp = fa[fu] + fa[fv];
    if (fa[fu] <= fa[fv]) {
        fa[fu] = tmp;
        fa[fv] = fu;
    } else {
        fa[fv] = tmp;
        fa[fu] = fv;
    }
}

void kruskal(){
    for (int i = 0; i < tot; ++ i) {
        if (findfa(e[i].u) != findfa(e[i].v)) {
            unionedge(e[i].u, e[i].v);
            ans += e[i].w;
        }
    }
}


int main() {
    scanf("%d%d",&n,&k);
    int v;
    init();
    for (int i = 0; i < k; ++ i) {
        scanf("%d",&v);
        pos[v] = 1;
    }
    
    for (int i = 1; i <= n; ++ i) {
        if (!pos[i]) {
            pos[i] = m ++;
        }
    }
    
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            scanf("%d",&mp[pos[i]][pos[j]]);
            if (i < j) {
                e[tot].u = pos[i];
                e[tot].v = pos[j];
                e[tot ++].w = mp[pos[i]][pos[j]];
            }
        }
    }
    
    sort(e, e + tot);
    
    ans = 0;
    
    kruskal();
    
    printf("%d\n",ans);
    return 0;
}
