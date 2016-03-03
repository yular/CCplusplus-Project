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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 200;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
int arr[N];
int dp[N][N], col[N][N];
int n;

void init(){
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < n; ++ i) {
        dp[i][i] = 0;
        col[i][i] = arr[i];
    }
}

void solve(){
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = i + 1; j < n; ++ j) {
            for (int k = i; k < j; ++ k) {
                int val = dp[i][k] + dp[k+1][j] + col[i][k]*col[k + 1][j];
                if (val < dp[i][j]) {
                    dp[i][j] = val;
                    col[i][j] = (col[i][k] + col[k + 1][j])%MOD;
                }
            }
        }
    }
}

int main() {
    while (scanf("%d",&n) == 1) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&arr[i]);
        }
        init();
        solve();
        printf("%d\n",dp[0][n - 1]);
    }
    return 0;
}
