/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(1)
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
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n;
int dp[M][M], mp[M][M];

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        for (int i = 0; i <= n/2; ++ i) {
            for (int j = 0; j <= i; ++ j) {
                scanf("%d",&dp[i][j]);
                if (i > 0) {
                    if (j == 0) {
                        dp[i][j] = dp[i - 1][j] + dp[i][j];
                    } else if(j == i){
                        dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
                    } else {
                        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];
                    }
                }
            }
        }
        for (int i = n/2 + 1; i < n; ++ i) {
            for (int j = 0; j < n - i; ++ j) {
                scanf("%d",&dp[i][j]);
                dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j]) + dp[i][j];
            }
        }
        printf("%d\n",dp[n - 1][0]);
    }
    return 0;
}
