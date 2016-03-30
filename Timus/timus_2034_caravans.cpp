/*
 *
 * Tag: BFS + Binary Search
 * Time: O(nlgn)
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
const int N = 100510;
const int M = 300310;
const long long MOD = 1000000007;
const double eps = 1e-10;
struct node{
    int u, v;
    int next;
}e[M];
int head[N], num, sdis[N], dis[N];
int n, m, ans, mid;
bool vis[N];
int s, t, r;

void init(){
    num = 0;
    for (int i = 0; i <= n + 1; ++ i) {
        head[i] = -1;
        sdis[i] = dis[i] = INT_MAX;
    }
}

void addedge(int u, int v){
    e[num].u = u;
    e[num].v = v;
    e[num].next = head[u];
    head[u] = num ++;
}

void bfs(int s, int t, int dis[]){
    memset(vis, 0, sizeof(vis));
    vis[s] = 1;
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (!vis[v] && dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int sp(){
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[s] = 0;
    vis[s] = 1;
    if (sdis[s] <= mid) {
        return INT_MAX;
    }
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (sdis[v] <= mid) {
                continue;
            }
            if (!vis[v] && dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return dis[t];
}


int main() {
    scanf("%d%d",&n,&m);
    init();
    for (int i = 0; i < m; ++ i) {
        int u, v;
        scanf("%d%d",&u,&v);
        addedge(u, v);
        addedge(v, u);
    }
    scanf("%d%d%d",&s,&t,&r);
    bfs(r, t, sdis);
    bfs(s, t, dis);
    ans = dis[t];
    
    int l = 0, r = n;
    while (l < r) {
        mid = (l + r)/2;
        int res = sp();
        if (res == ans) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    printf("%d\n",l);
    return 0;
}
