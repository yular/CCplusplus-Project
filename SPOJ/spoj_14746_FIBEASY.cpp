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
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
long long dp[M];
int n;

void init(){
    dp[0] = 0;
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= 60; ++ i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        printf("%lld",dp[1]);
        for (int i = 2; i <= n; ++ i) {
            printf(" %lld",dp[i]);
        }
        puts("");
    }
    return 0;
}
