/*
*
* Tag: DP
* Time: O(n^3)
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
const int M = 2100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int dp[N][N*N];
int n, k, num[N];

void init() {
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    dp[2][0] = dp[2][1] = 1;
    dp[3][0] = dp[3][3] = 1;
    dp[3][1] = dp[3][2] = 2;
    num[1] = 1;
    for (int i = 2; i <= 12; ++ i)
        num[i] = num[i - 1] + (i - 1);
        
    for (int i = 4; i <= 12; ++ i) {
        for (int j = 0; j < num[i - 1]; ++ j) {
            for (int k = 0; k < i; ++ k) {
                dp[i][j + k] += dp[i - 1][j];
            }
        }
        for (int j = 0; j <= num[i]/2; ++ j) {
            dp[i][num[i] - j - 1] = dp[i][j];
        }
    }
}

int main(){
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&k);
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
