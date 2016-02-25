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
const int N = 500;
const int M = 20;
const double eps = 1e-10;
char mp[N][N];
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
int n, m, ans;

void dfs(int x, int y){
    for (int i = 0; i < 8; ++ i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] == '#') {
            mp[nx][ny] = '.';
            dfs(nx, ny);
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        ans = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%s",mp[i]);
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (mp[i][j] == '#') {
                    mp[i][j] = '.';
                    dfs(i, j);
                    ++ ans;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
