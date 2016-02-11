/*
*
* Tag: Graph (Floyd)
* Time: O(n^3)
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
const int N = 300;
const int M = 12011;
const int MOD = 10037;
const double dinf = 1e20;
const double eps = 1e-6;
int n;
int mp[N][N], g[N][N];
bool notneigh[N][N];

void init(){
    memset(notneigh, 0, sizeof(notneigh));
}

void floyd(){
    for (int k = 1; k <= n; ++ k) {
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (g[i][j] >= g[i][k] + g[k][j] && i != k && j != k) {
                    notneigh[i][j] = true;
                }
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}


int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        init();
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                scanf("%d",&mp[i][j]);
                g[i][j] = mp[i][j];
            }
        }
        floyd();
        for (int i = 1; i <= n; ++ i) {
            for (int j = i + 1; j <= n; ++ j) {
                if (!notneigh[i][j]) {
                    printf("%d %d\n",i,j);
                }
            }
        }
        if (T) {
            puts("");
        }
    }
    return 0;
}
