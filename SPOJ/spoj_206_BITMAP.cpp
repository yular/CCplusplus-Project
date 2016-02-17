/*
*
* Tag: BFS
* Time: O(nm)
* Space: O(nm)
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
const int N = 310;
const int M = 101010;
const double eps = 1e-10;
int n, m;
char mp[N][N];
int dis[N][N];
bool vis[N][N];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void init(){
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        init();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++ i) {
            scanf("%s",mp[i]);
            for (int j = 0; j < m; ++ j) {
                if (mp[i][j] == '1') {
                    dis[i][j] = 0;
                    vis[i][j] = 1;
                    q.push(make_pair(i, j));
                } else {
                    dis[i][j] = INT_MAX;
                }
            }
        }
        
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int i = 0; i < 4; ++ i) {
                int nx = cur.first + dir[i][0], ny = cur.second + dir[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    dis[nx][ny] = dis[cur.first][cur.second] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                printf("%d ",dis[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
