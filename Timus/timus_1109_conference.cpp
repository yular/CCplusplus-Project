/*
*
* Tag: Graph (Minimum Edge Covering)
* Time: O(n^3) or O(n*m)
* Space: O(n^2)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
const int N = 1200;
const int M = 12011;
const int MOD = 10037;
const double dinf = 1e20;
const double eps = 1e-6;
int n, m, k, ans;
bool mp[N][N], vis[N];
int res[N];

void init(){
    memset(mp, 0, sizeof(mp));
    memset(res, 0, sizeof(res));
    ans  = 0;
    for (int i = 0; i < k; ++ i) {
        int u, v;
        scanf("%d%d",&u,&v);
        mp[u][v] = 1;
    }
}

bool find(int u){
    for (int i = 1; i <= m; ++ i) {
        if (mp[u][i] && !vis[i]) {
            vis[i] = 1;
            if (res[i] == 0 || find(res[i])) {
                res[i] = u;
                return true;
            }
        }
    }
    return false;
}

void solve(){
    for (int i = 1; i <= n; ++ i) {
        memset(vis, 0, sizeof(vis));
        if (find(i)) {
            ++ ans;
        }
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    init();
    solve();
    printf("%d\n",n + m - ans);
    return 0;
}
