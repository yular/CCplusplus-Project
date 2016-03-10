/*
 *
 * Tag: DP
 * Time: O(n)
 * Space: O(n)
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
const int N = 20000011;
const int M = 1010;
const long long MOD = 1000000007;
const double eps = 1e-10;
int dp[N], n;

void init(){
    dp[1] = 0;
    for (int i = 2; i < N; ++ i) {
        int minval = dp[i - 1];
        if (i%3 == 0) {
            minval = min(minval, dp[i/3]);
        }
        if (i%2 == 0) {
            minval = min(minval, dp[i/2]);
        }
        dp[i] = minval + 1;
    }
}

int main() {
    init();
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        printf("Case %d: %d\n",cas++,dp[n]);
    }
    return 0;
}
