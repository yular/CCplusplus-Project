/*
 *
 * Tag: DFS
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
const int N = 1050000;
const int M = 120;
const double eps = 1e-10;
int n, m, pcnt, rcnt;
char mp[M][M];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y){
    if (mp[x][y] == '*') {
        ++ pcnt;
    }
    mp[x][y] = '#';
    for (int i = 0; i < 4; ++ i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] != '#') {
            dfs(nx, ny);
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        pcnt = rcnt = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%s",mp[i]);
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (mp[i][j] == '#') {
                    continue;
                }
                dfs(i, j);
                ++ rcnt;
            }
        }
        double ans = 0;
        if (rcnt) {
            ans = (double)pcnt/(double)rcnt;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
