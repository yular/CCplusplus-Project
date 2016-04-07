/*
 *
 * Tag: LCA
 * Time: O(n + q)
 * Space: O(n)
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 80100;
const int M = 100;
const long long MOD = 1000000007;
const double eps = 1e-10;
struct edge{
    int u, v, w;
    int nxt;
}e[4*N];
int head[N], q[N], num;
int dis[N], fa[N], ans[N];
bool vis[N];
int n, m;

void init(){
    num = 0;
    for (int i = 0; i < N; ++ i) {
        head[i] = q[i] = fa[i] = -1;
        dis[i] = vis[i] = 0;
    }
}

void addedge(int u, int v, int w){
    e[num].u = u;
    e[num].v = v;
    e[num].w = w;
    e[num].nxt = head[u];
    head[u] = num ++;
}

void addq(int u, int v, int w){
    e[num].u = u;
    e[num].v = v;
    e[num].w = w;
    e[num].nxt = q[u];
    q[u] = num ++;
}

int findpa(int u){
    return fa[u] == -1? u : fa[u]=findpa(fa[u]);
}

void tarjan(int u, int tmpdis){
    vis[u] = 1;
    dis[u] = tmpdis;
    for (int i = q[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v, id = e[i].w;
        if (vis[v]) {
            ans[id] = dis[u] + dis[v] - 2*dis[findpa(v)];
        }
    }
    for (int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v, w = e[i].w;
        if (!vis[v]) {
            tarjan(v, tmpdis + w);
            fa[v] = u;
        }
    }
}

int main() {
    init();
    scanf("%d",&n);
    for (int i = 1; i < n; ++ i) {
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++ i) {
        int u, v;
        scanf("%d%d",&u,&v);
        addq(u, v, i);
        addq(v, u, i);
    }
    tarjan(0, 0);
    for (int i = 0; i < m; ++ i) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
