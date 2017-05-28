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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 20;
const int M = 150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int ship[M], r[N], ans[N][M];
bool vis[M];
int n, m;
bool isfind;

void dfs(int dep){
    if (dep >= m) {
        isfind = true;
        return ;
    }
    for (int i = 0; i < n; ++ i) {
        if (!vis[i] && ship[i] <= r[dep]) {
            r[dep] -= ship[i];
            vis[i] = 1;
            ++ ans[dep][0];
            ans[dep][ ans[dep][0] ] = ship[i];
            if (r[dep] == 0) {
                dfs(dep + 1);
            } else {
                dfs(dep);
            }
            if (isfind) {
                return ;
            }
            r[dep] += ship[i];
            vis[i] = 0;
            -- ans[dep][0];
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&ship[i]);
    }
    sort(ship, ship + n, greater<int>());
    for (int i = 0; i < m; ++ i) {
        scanf("%d",&r[i]);
    }
    isfind = false;
    dfs(0);
    for (int i = 0; i < m; ++ i) {
        printf("%d\n",ans[i][0]);
        for (int j = 1; j <= ans[i][0]; ++ j) {
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
    return 0;
}
