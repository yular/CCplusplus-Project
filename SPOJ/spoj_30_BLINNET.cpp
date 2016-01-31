/*
*
* Tag: Graph
* Time: O(|E|lg|E|)
* Space: O(|E|)
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
using namespace std;
const int N = 10100;
const int M = 10001010;
const int NN = 100;
struct edge{
    int u, v, w;
    bool operator < (const edge a) const {
        return w < a.w;
    }
}e[M];
int n, num, ans;
int fa[N];
char s[NN];

void init(){
    num = 0;
    ans = 0;
    for (int i = 0; i < N; ++ i) {
        fa[i] = -1;
    }
}

int find(int u){
    int s = u;
    for (; fa[s] >= 0; s = fa[s]) ;
    while (s != u) {
        int tmp = fa[u];
        fa[u] = s;
        u = tmp;
    }
    return s;
}

void unionedge(int u, int v){
    int f1 = find(u), f2 = find(v);
    int tmp = fa[f1] + fa[f2];
    if (fa[f1] < fa[f2]) {
        fa[f1] = tmp;
        fa[f2] = f1;
    } else {
        fa[f2] = tmp;
        fa[f1] = f2;
    }
}

void kruskal(){
    sort(e, e + num);
    for (int i = 0; i < num; ++ i) {
        int u = e[i].u, v = e[i].v;
        if (find(u) != find(v)) {
            unionedge(u, v);
            ans += e[i].w;
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        init();
        for (int i = 1; i <= n; ++ i) {
            int p;
            scanf("%s",s);
            scanf("%d",&p);
            for (int j = 0; j < p; ++ j) {
                int v, w;
                scanf("%d%d",&v,&w);
                if (i < v) {
                    e[num].u = i;
                    e[num].v = v;
                    e[num].w = w;
                    ++ num;
                }
            }
        }
        kruskal();
        printf("%d\n",ans);
    }
    return 0;
}
