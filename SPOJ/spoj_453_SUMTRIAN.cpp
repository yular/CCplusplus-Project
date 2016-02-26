/*
 *
 * Tag: DP
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 500;
const int M = 20;
const double eps = 1e-10;
int n;
int dp[N][N];

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        int ans = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j <= i; ++ j) {
                scanf("%d",&dp[i][j]);
            }
        }
        ans = dp[0][0];
        for (int i = 1; i < n; ++ i) {
            for (int j = 0; j <= i; ++ j) {
                if (!j) {
                    dp[i][j] += dp[i - 1][j];
                } else {
                    dp[i][j] += max(dp[i - 1][ j - 1], dp[i - 1][j]);
                }
                ans = max(dp[i][j], ans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
