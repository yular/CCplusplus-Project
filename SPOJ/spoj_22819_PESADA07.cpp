/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
#include <stdio.h>
#include <string.h>
const int M = 300;
const long long MOD = 495;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, ans;

void dfs(int u, int mp[M][M], int vis[M]){
    vis[u] = 1;
    for (int i = 0; i < n; ++ i) {
        if(mp[u][i] && !vis[i]){
            dfs(i, mp, vis);
        }
    }
}

int main(){
	int mp[M][M], vis[M];
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        memset(vis, 0, sizeof(vis));
        ans = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d",&mp[i][j]);
            }
        }
        for (int i = 0; i < n; ++ i) {
            if (!vis[i]) {
                ++ ans;
                dfs(i, mp, vis);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
