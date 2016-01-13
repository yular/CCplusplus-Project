/*
*
* Tag: Graph
* Time: O(mlgm)
* Space: O(n+m)
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 1010;
const int M = 100100;
//const int INF = 1<<29;
struct edge{
    int u, v, w;
    bool operator < (const edge a)const {
        return w < a.w;
    }
}gdset[M],bdset[M];
int n, m, p;
int fa[N], tot, gdcnt, bdcnt;
bool badbuild[N], intree[N];
long long ans;

void init(){
    
    memset(badbuild, 0, sizeof(badbuild));
    memset(intree, 0, sizeof(intree));
    
    gdcnt = bdcnt = tot = 0;
    ans = 0;
    
    for (int i = 0; i <= n; ++ i) {
        fa[i] = -1;
    }
    
}

int find(int u){
    
    int s = u;
    for (; fa[s] >= 0; s = fa[s]) ;
    
    while (u != s) {
        int tmp = fa[u];
        fa[u] = s;
        u = tmp;
    }
    return s;
}

void unionedge(int a, int b){
    
    int fa1 = find(a), fa2 = find(b);
    int tmp = fa[fa1] + fa[fa2];
    
    if (fa[fa1] <= fa[fa2]) {
        fa[fa1] = tmp;
        fa[fa2] = fa1;
    } else {
        fa[fa1] = fa2;
        fa[fa2] = tmp;
    }
    
}

void kruskal(){
    
    if (gdcnt == 0 && bdcnt == 1){
        ans += bdset[0].w;
        unionedge(bdset[0].u, bdset[0].v);
        return ;
    }
    
    for (int i = 0; i < gdcnt; ++ i) {
        int u = gdset[i].u, v = gdset[i].v;
        if (find(u) != find(v)) {
            unionedge(u, v);
            intree[u] = intree[v] = 1;
            ans += gdset[i].w;
        }
    }
    
    for (int i = 0; i < bdcnt; ++ i) {
        int u = bdset[i].u, v = bdset[i].v;
        if (find(u) != find(v)) {
            if ((badbuild[u] && intree[u]) || (badbuild[v] && intree[v]) || (badbuild[u] && badbuild[v]))
                continue;
            unionedge(u, v);
            intree[u] = intree[v] = 1;
            ans += bdset[i].w;
        }
    }
}

int main() {

    //    freopen("/Users/baiyang/Project/CCPP/USACO/USACO/text_editor.txt", "r", stdin);
    //    freopen("/Users/baiyang/Project/CCPP/USACO/USACO/text_editor.out", "w", stdout);
    
    while (scanf("%d%d%d",&n,&m,&p) == 3) {
        //    printf(" -- %d %d %d\n",n,m,p);
        int u, v, w;
        
        init();
        
        for (int i = 0; i < p; ++ i) {
            scanf("%d",&v);
            badbuild[v] = 1;
        }
        
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d%d",&u,&v,&w);
            
            if(!badbuild[u] && !badbuild[v]){
                gdset[gdcnt].u = u;
                gdset[gdcnt].v = v;
                gdset[gdcnt].w = w;
                ++ gdcnt;
            }else{
                bdset[bdcnt].u = u;
                bdset[bdcnt].v = v;
                bdset[bdcnt].w = w;
                ++ bdcnt;
            }
            
        }
        
        sort(gdset, gdset + gdcnt);
        
        if (bdcnt) {
            sort(bdset, bdset + bdcnt);
        }
        
        kruskal();
        
        for (int i = 1; i <= n; ++ i) {
            if (fa[i] < 0)
                ++ tot;
        }
        
        if (tot == 1 || !m) {
            printf("%lld\n",ans);
        } else {
            puts("impossible");
        }
        
    }
    
    return 0;
}
