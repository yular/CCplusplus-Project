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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 1000200;
const int M = 50000;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
int n;
double p, dp[N][2];

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%lf",&n,&p);
        dp[0][0] = 1 - p;
        dp[0][1] = p;
        for (int i = 1; i < n; ++ i) {
            dp[i][0] = dp[i - 1][0]*(1 - p) + dp[i - 1][1]*p;
            dp[i][1] = dp[i - 1][0]*p + dp[i - 1][1]*(1 - p);
        }
        printf("%.6lf\n",dp[n - 1][1]);
    }
    return 0;
}
