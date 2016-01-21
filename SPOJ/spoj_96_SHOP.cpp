/*
*
*
* Tag: Graph
* Time: O(|E| + |V|log|V|)
* Space: O(|E| + |V|)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 1010;
const int M = 5020;
//const int INF = 1<<29;
int n, m;
struct edge{
    int u, v, w;
    int next;
}e[M];
int head[N], num, dis[N];
char mp[N][N];
int dir[4][2] = {{1,0},{-1, 0}, {0, 1}, {0, -1}};
int s, d;

struct cmp {
    bool operator() (const int &a, const int &b){
        return dis[a] > dis[b];
    }
};

void init(){
    num = 0;
    for (int i = 0; i < N; ++ i) {
        head[i] = -1;
        dis[i] = INT_MAX;
    }
}

void addedge(int u, int v, int w){
    e[num].u = u;
    e[num].v = v;
    e[num].w = w;
    e[num].next = head[u];
    head[u] = num ++;
}

void dijk(){
    priority_queue<int, vector<int>, cmp > pq;
    while (!pq.empty()) {
        pq.pop();
    }
    dis[s] = 0;
    pq.push(s);
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        if (u == d) {
            break;
        }
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                pq.push(v);
            }
        }
    }
}

int main() {

    while (scanf("%d%d",&m,&n)==2 && m && n) {
        init();
        for (int i = 0; i < n; ++ i) {
            scanf("%s",mp[i]);
        }
        
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                int u = i*m + j;
                if (mp[i][j] == 'S') {
                    s = u;
                }else if (mp[i][j] == 'D'){
                    d = u;
                }
                for (int k = 0; k < 4; ++ k) {
                    int nx = i + dir[k][0], ny = j + dir[k][1];
                    int v = nx*m + ny;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] != 'X') {
                        int w;
                        if (mp[nx][ny] >= '0' && mp[nx][ny] <= '9') {
                            w = (mp[nx][ny] - '0');
                        } else {
                            w = 0;
                        }
                        addedge(u, v, w);
                    }
                }
            }
        }
        dijk();
        printf("%d\n",dis[d]);
    }
    return 0;
}
