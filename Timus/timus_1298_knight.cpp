/*
*
* Tag: DFS
* Time: O((n^2)!)
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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 15;
const int M = 150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, top, vis[N][N];
string stk[M];
bool accall;
int dir[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

inline bool isInMap(int r, int c){
    return r >= 1 && r <= n && c >= 1 && c <= n && !vis[r][c];
}

void dfs(int r, int c, int dep){
    if (dep >= n*n) {
        accall = true;
        return ;
    }
    for (int i = 0; i < 8; ++ i) {
        int x = r + dir[i][0], y = c + dir[i][1];
        if (isInMap(x, y)) {
            vis[x][y] = dep + 1;
            dfs(x, y, dep + 1);
            if (accall) {
                return ;
            }
            vis[x][y] = 0;
        }
    }
}

int main(){
    scanf("%d",&n);
    memset(vis, 0, sizeof(vis));
    if (n <= 4 && n > 1) {
        puts("IMPOSSIBLE");
    } else if (n == 1) {
        puts("a1");
    } else {
        accall = false;
        vis[1][1] = 1;
        dfs(1, 1, 1);
        if (accall) {
            for (int k = 1; k <= n*n; ++ k) {
                for (int i = 1; i <= n; ++ i) {
                    for (int j = 1; j <= n; ++ j) {
                        if (vis[i][j] == k) {
                            printf("%c%d\n",i+'a'-1,j);
                        }
                    }
                }
            }
        } else {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
