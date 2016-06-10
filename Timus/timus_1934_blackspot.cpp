/*
*
* Tag: Graph
* Time: O(|E| + |V|lg|V|)
* Space: O(|V|)
*
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
const int N = 100050;
const int M = 1030110;
const long long MOD = 1000000007;
const double eps = 1e-10;
struct edge{
    int u, v;
    double p;
    int nxt;
}e[M];
int head[N], num;
int n, m, s, t;
int dis[N], pre[N], ans[N];
bool inq[N];
double pdis[N], ansp;

void init(){
    for (int i = 0; i <= n + 1; ++ i) {
        head[i] = -1;
        dis[i] = INT_MAX;
        pdis[i] = 2.0;
        pre[i] = -1;
        inq[i] = false;
    }
    num = 0;
    ansp = 0;
}

void addedge(int u, int v, double p){
    e[num].u = u;
    e[num].v = v;
    e[num].p = (1 - p);
    e[num].nxt = head[u];
    head[u] = num ++;
}

struct cmp{
    bool operator() (const int &a, const int &b){
        if (dis[a] == dis[b])
            return pdis[b] > pdis[a];
        else
            return dis[a] > dis[b];
    }
};

priority_queue<int, vector<int>, cmp> pq;
void dijk(){
    pre[s] = -1;
    dis[s] = 0;
    pdis[s] = 1;
    pq.push(s);
    inq[s] = 1;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        inq[s] = 0;
        for (int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                pdis[v] = pdis[u]*e[i].p;
                pre[v] = u;
                if (!inq[v]) {
                    inq[v] = 1;
                    pq.push(v);
                }
            }else if (dis[v] == dis[u] + 1) {
                if (pdis[v] < pdis[u]*e[i].p) {
                    pdis[v] = pdis[u]*e[i].p;
                    pre[v] = u;
                    if (!inq[v]) {
                        inq[v] = 1;
                        pq.push(v);
                    }
                }
            }
        }
    }
}



int main() {
    scanf("%d%d",&n,&m);
    init();
    scanf("%d%d",&s,&t);
    for (int i = 0; i < m; ++ i) {
        int u, v;
        double p;
        scanf("%d%d%lf",&u,&v,&p);
        p = p/100.0;
        addedge(u, v, p);
        addedge(v, u, p);
    }
    dijk();
    printf("%d %.6lf\n",dis[t]+1,1-pdis[t]);
    int cnt = 0, id = t;
    ans[cnt ++] = t;
    while (pre[id] != -1) {
        id = pre[id];
        ans[cnt ++] = id;
    }
    for (int i = cnt - 1; i >= 0; -- i) {
        printf("%d ",ans[i]);
    }
    puts("");
    return 0;
}
