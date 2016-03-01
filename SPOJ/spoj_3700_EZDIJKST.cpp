/*
 *
 * Tag: Graph (Dijkstra)
 * Time: O(E + VlgV)
 * Space: O(V)
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
const int N = 10050;
const int M = 10020;
const double eps = 1e-10;
struct edge{
    int u, v, w;
    int nxt;
}e[M];
int head[N], num;
int v, k, s, t;
int dis[N];

struct cmp{
    bool operator() (const int &a, const int &b){
        return dis[a] > dis[b];
    }
};

void addedge(int u, int v, int w){
    e[num].u = u;
    e[num].v = v;
    e[num].w = w;
    e[num].nxt = head[u];
    head[u] = num ++;
}

void init(){
    for (int i = 0; i < N; ++ i) {
        dis[i] = INT_MAX;
    }
    num = 0;
    for (int i = 0; i < M; ++ i) {
        head[i] = -1;
    }
}

void dijk(){
    priority_queue<int, vector<int>, cmp > pq;
    dis[s] = 0;
    pq.push(s);
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v, w = e[i].w;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push(v);
            }
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        init();
        scanf("%d%d",&v,&k);
        for (int i = 0; i < k; ++ i) {
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);
            addedge(a, b, c);
        }
        scanf("%d%d",&s,&t);
        dijk();
        if (dis[t] == INT_MAX) {
            puts("NO");
        } else {
            printf("%d\n",dis[t]);
        }
    }
    return 0;
}
