/*
 *
 * Tag: Graph
 * Time: O(n^2)
 * Space: O(n^2)
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
const int N = 1050;
const int M = 20;
const double eps = 1e-10;
int n, m;
bool mp[N][N], vis[N];
int que[N], front, rear;
int s, op;

void init(){
    memset(mp, 0, sizeof(mp));
}

void dfs(int u){
    if (u != s) {
        printf(" %d",u);
    }
    for (int i = 1; i <= n; ++ i) {
        if (mp[u][i] && !vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    int T, cnt = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        init();
        for (int i = 1; i <= n; ++ i) {
            int u, v;
            scanf("%d%d",&u,&m);
            for (int i = 0; i < m; ++ i) {
                scanf("%d",&v);
                mp[u][v] = mp[v][u] = 1;
            }
        }
        printf("graph %d\n", cnt ++);
        while (scanf("%d%d",&s,&op) == 2) {
            if (!s && !op) {
                break;
            }
            memset(vis, 0, sizeof(vis));
            if (op == 0) {
                vis[s] = 1;
                printf("%d",s);
                dfs(s);
            } else {
                bool isfirst = true;
                front = rear = 0;
                que[rear ++] = s;
                vis[s] = 1;
                while (front < rear) {
                    int u = que[front ++];
                    if (!isfirst) {
                        printf(" ");
                    }
                    printf("%d",u);
                    isfirst = false;
                    for (int i = 1; i <= n; ++ i) {
                        if (mp[u][i] && !vis[i]) {
                            que[rear ++] = i;
                            vis[i] = 1;
                        }
                    }
                }
            }
            puts("");
        }

    }
    return 0;
}
