/*
 *
 * Tag: DP (or Math)
 * Time: O(n) (Best: O(1))
 * Space: O(n) (Best: O(1))
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
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
int dp[M];
int n;

void init(){
    dp[0] = 0;
    for (int i = 1; i <= 110; ++ i) {
        dp[i] = dp[i - 1] + 3*i;
    }
}

int main() {
    init();
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        printf("Case #%d: %d\n",cas ++,dp[n]);
    }
    return 0;
}
