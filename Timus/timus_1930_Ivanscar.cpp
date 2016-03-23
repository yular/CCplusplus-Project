/*
 *
 * Tag: Graph (BFS)
 * Time: O(n)
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
const int N = 101000;
const int M = 10310;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n, m;
struct node{
    int u, v, type;
    int nxt;
}e[N];
int head[M], num;
int dis[M][2];
queue<pair<int, int>> q;
int s, t;

void init(){
    num = 0;
    for (int i = 0; i < M; ++ i) {
        head[i] = -1;
        dis[i][0] = dis[i][1] = INT_MAX;
    }
}

void addedge(int u, int v, int type){
    e[num].u = u;
    e[num].v = v;
    e[num].type = type;
    e[num].nxt = head[u];
    head[u] = num ++;
}

void bfs(){
    dis[s][0] = dis[s][1] = 0;
    q.push(make_pair(s, 0));
    q.push(make_pair(s, 1));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int u = cur.first, type = cur.second;
        for (int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v, w = dis[u][type], type_nxt = e[i].type;
            if (type != type_nxt) {
                ++ w;
            }
            if (dis[v][type_nxt] > w) {
                dis[v][type_nxt] = w;
                q.push(make_pair(v, type_nxt));
            }
        }
    }
}

int main() {
    init();
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++ i) {
        int u, v;
        scanf("%d%d",&u,&v);
        addedge(u, v, 0);
        addedge(v, u, 1);
    }
    scanf("%d%d",&s,&t);
    bfs();
    printf("%d\n",min(dis[t][0], dis[t][1]));
    return 0;
}
