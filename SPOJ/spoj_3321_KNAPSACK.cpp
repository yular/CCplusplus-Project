/*
 *
 * Tag: DP
 * Time: O(ns)
 * Space: O(s)
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
const int N = 3000;
const int M = 120;
const double eps = 1e-10;
int s, n;
int dp[N], item[N][2];

int main() {
    scanf("%d%d",&s,&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d",&item[i][0],&item[i][1]);
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = s; j >= item[i][0]; -- j) {
            dp[j] = max(dp[j], dp[j - item[i][0]] + item[i][1]);
        }
    }
    printf("%d\n",dp[s]);
    return 0;
}
