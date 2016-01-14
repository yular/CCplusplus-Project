/*
*
* Tag: DP
* Time: O(nmm)
* Space: O(O(nm), O(mm))
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 130;
const int M = 110;
//const int INF = 1<<29;
int n, m;
int score[M][M];
int arr[N];
int dp[N][M];

int main() {

    //    freopen("/Users/baiyang/Project/CCPP/USACO/USACO/text_editor.txt", "r", stdin);
    //    freopen("/Users/baiyang/Project/CCPP/USACO/USACO/text_editor.out", "w", stdout);
//    ninit();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= m; ++ i){
            for (int j = 1; j <= m; ++ j) {
                scanf("%d",&score[i][j]);
            }
        }
        for (int i = 1; i <= n; ++ i) {
            scanf("%d",&arr[i]);
        }
        for (int i = 2; i <= n; ++ i) {
            if (arr[i] < 0) {
                for (int j = 1; j <= m; ++ j) {
                    if (arr[i - 1] > 0) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][ arr[i - 1] ] + score[ arr[i - 1] ][j]);
                    } else {
                        for (int k = 1; k <= m; ++ k) {
                            dp[i][j] = max(dp[i][j], dp[i - 1][k] + score[k][j]);
                        }
                    }
                }
            } else {
                if (arr[i - 1] > 0) {
                    dp[i][ arr[i] ] = max(dp[i][ arr[i] ], dp[i - 1][ arr[i - 1] ] + score[ arr[i - 1] ][ arr[i] ]);
                } else {
                    for (int j = 1; j <= m;  ++ j) {
                        dp[i][ arr[i] ] = max(dp[i][ arr[i] ], dp[i - 1][ j ] + score[ j ][ arr[i] ]);
                    }
                }
            }
        }
        for (int i = 1; i <= m; ++ i) {
            ans = max(ans, dp[n][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
    
}
