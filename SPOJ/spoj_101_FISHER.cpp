/*
*
* Tag: DP
* Time: O(TN^2)
* Space: O(TN + N^2)
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
const int N = 1030;
const int M = 100;
const int MOD = 10037;
const double eps = 1e-6;
int n, t;
int dp[N][M];
int timap[M][M],tlmap[M][M];

void init(){
    for (int i = 0; i <= t; ++ i) {
        for (int j = 0; j < n; ++ j) {
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = 0;
}

int main(){
    while (scanf("%d%d",&n,&t) == 2) {
        if (!n && !t) {
            break;
        }
        init();
        for (int i =0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d",&timap[i][j]);
            }
        }
        for (int i =0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d",&tlmap[i][j]);
            }
        }
        for (int i = 1; i <= t; ++ i) {
            for (int j = 0; j < n; ++ j) {
                for (int k = 0; k < n; ++ k) {
                    if (k != j && timap[k][j] <= i && dp[ i - timap[k][j] ][k] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[ i - timap[k][j] ][k] + tlmap[k][j]);
                    }
                }
            }
        }
        int ansti = 1;
        int anstl = INT_MAX;
        for (int i = 1; i <= t; ++ i) {
            if (dp[i][n - 1] < anstl) {
                anstl = dp[i][n - 1];
                ansti = i;
            }
        }
        printf("%d %d\n",anstl, ansti);
    }
    return 0;
}
