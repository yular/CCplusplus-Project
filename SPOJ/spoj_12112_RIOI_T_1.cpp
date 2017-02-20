/*
*
* Tag: Math
* Time: O(nk)
* Space: O(nk)
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
const int N = 2000030;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, k;
long long dp[M][M];

void init(){
    memset(dp, 0, sizeof(dp));
    dp[0][0] = dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < 22; ++ i) {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; ++ j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}

int main(){
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&k);
        printf("%lld\n",dp[n][k]);
    }
    return 0;
}
