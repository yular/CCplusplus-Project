/*
*
* Tag: DP
* Time: O(nta)
* Space: O(ta)
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
const int N = 30;
const int M = 100;
const int NN = 1010;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int dp[2][N][M], itm[NN][3];
int n, t, a;

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&t,&a);
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d%d",&itm[i][0],&itm[i][1],&itm[i][2]);
        }
        for (int i = 0; i <= t; ++ i) {
            for (int j = 0; j <= a; ++ j) {
                dp[1][i][j] = MAX_VAL;
            }
        }
        dp[1][0][0] = 0;
        for (int i = 0, cur = 0; i < n; ++ i, cur ^= 1 ) {
            for (int ox = 0; ox <= t; ++ ox ) {
                for (int nt = 0; nt <= a; ++ nt ) {
                    dp[cur][ox][nt] = min(dp[cur^1][ox][nt], dp[cur^1][max(0, ox - itm[i][0])][max(0, nt - itm[i][1])] + itm[i][2]);
                }
            }
        }
        printf("%d\n",dp[(n-1)&1][t][a]);
    }
    return 0;
}
