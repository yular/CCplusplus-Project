/*
*
* Tag: Graph (Dijk)
* Time: O(|E| + |V|lg|V|)
* Space: O(|V|)
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
using namespace std;
const int N = 1000010;
const int M = 1010000;
struct edge{
    int u, v, w;
    int next;
}e[M], re[M];
int head[N], rhead[N];
int num, rnum;
int n, m, s;
int dist[N];
long long ans;

struct cmp{
    bool operator() (const int &a, const int &b){
        return dist[a] > dist[b];
    }
};

priority_queue<int, vector<int>, cmp > pq;

void init(){
    num = rnum = 0;
    for (int i = 0; i <= n + 5; ++ i) {
        head[i] = rhead[i] = -1;
    }
    ans = 0;
    s = 1;
}

void addedge(int u, int v, int w){
    e[num].u = u;
    e[num].v = v;
    e[num].w = w;
    e[num].next = head[u];
    head[u] = num ++;
}

void addredge(int u, int v, int w){
    re[rnum].u = u;
    re[rnum].v = v;
    re[rnum].w = w;
    re[rnum].next = rhead[u];
    rhead[u] = rnum ++;
}

void initalgo(){
    for (int i = 0; i <= n; ++ i) {
        dist[i] = INT_MAX;
    }
    while (!pq.empty()) {
        pq.pop();
    }
}

void dijk(){
    initalgo();
    dist[s] = 0;
    pq.push(s);
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(v);
            }
        }
    }
    
    for (int i = 1;  i <= n; ++ i) {
        if (dist[i] != INT_MAX) {
            ans += dist[i];
        }
    }
}

void rdijk(){
    initalgo();
    dist[s] = 0;
    pq.push(s);
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        for (int i = rhead[u]; i != -1; i = re[i].next) {
            int v = re[i].v, w = re[i].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(v);
            }
        }
    }
    
    for (int i = 1;  i <= n; ++ i) {
        if (dist[i] != INT_MAX) {
            ans += dist[i];
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        init();
        for (int i = 0; i < m; ++ i) {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u, v, w);
            addredge(v, u, w);
        }
        dijk();
        rdijk();
        printf("%lld\n",ans);
    }
    return 0;
}
