/*
*
* Tag: DFS
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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 110;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
char mp[N][N], s[N];
int n, len;
bool isfind, vis[N][N];

void dfs(int x, int y, int dep){
    if (dep >= len) {
        isfind = true;
        return ;
    }
    if (x < 0 || x >= 4 || y < 0 || y >= 4 || vis[x][y] || s[dep] != mp[x][y])
        return;
    vis[x][y] = true;
    for (int i = 0; i < 4; ++ i) {
        dfs(x + dir[i][0], y + dir[i][1], dep + 1);
        if (isfind)
            return ;
    }
    vis[x][y] = false;
}

bool check(){
    isfind = false;
    len = strlen(s);
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < 4; ++ j) {
            dfs(i, j, 0);
            if (isfind) {
                return true;
            }
        }
    }
    return false;
}

int main(){
    for (int i = 0; i < 4; ++ i)
        scanf("%s",mp[i]);
    scanf("%d",&n);
    while (n --) {
        memset(vis, 0, sizeof(vis));
        scanf("%s",s);
        if (check()) {
            printf("%s: YES\n",s);
        } else {
            printf("%s: NO\n",s);
        }
    }
    return 0;
}
