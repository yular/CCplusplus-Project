/*
 *
 * Tag: Graph
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
const int N = 10020;
const int M = 1030000;
const double eps = 1e-10;
struct edge{
    int u, v;
    int nxt;
}e[M];
int indeg[N], head[N], num;
int ans[N];
bool istoposort;
int n, m;

void init(){
    for (int i = 0; i <= n + 2; ++ i) {
        head[i] = -1;
        indeg[i] = 0;
    }
    num = 0;
    istoposort = true;
}

void addedge(int u, int v){
    e[num].u = u;
    e[num].v = v;
    e[num].nxt = head[u];
    head[u] = num ++;
}

void toposort(){
    int tmparr[N];
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    int tmpque[N], tmpfront = 0, tmprear = 0;
    for (int i = 1; i <= n; ++ i) {
        if (indeg[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int u = que.top();
        que.pop();
      //  printf(" u = %d\n", u);
        ans[cnt ++] = u;
        for (int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            -- indeg[v];
            if (!indeg[v]) {
                que.push(v);
            }
        }
    }
    if (cnt < n) {
        istoposort = false;
    }
}

int main() {
    scanf("%d%d",&n,&m);
    init();
    int x, y;
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d",&x,&y);
        addedge(x, y);
        ++ indeg[y];
    }
    toposort();
    if (istoposort) {
        bool isfirst = true;
        for (int i = 0; i < n; ++ i) {
            if (!isfirst) {
                printf(" ");
            }
            printf("%d",ans[i]);
            isfirst = false;
        }
        puts("");
    } else {
        puts("Sandro fails.");
    }
    return 0;
}
