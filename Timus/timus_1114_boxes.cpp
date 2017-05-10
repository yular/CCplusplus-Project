/*
*
* Tag: DP
* Time: O(NA^2B^2)
* Space: O(NAB)
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
const int N = 33000;
const int M = 50;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, A, B;
unsigned long long ans, dp[M][M][M];

int main(){
    ans = 0;
    cin>>n>>A>>B;
    memset(dp,0,sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j <= A; ++ j) {
            for (int k = 0; k <= B; ++ k) {
                for (int jj = 0; jj <= j; ++ jj) {
                    for (int kk = 0; kk <= k; ++ kk) {
                        dp[i][j][k] += dp[i - 1][jj][kk];
                    }
                }
                if (i == n) {
                    ans += dp[i][j][k];
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
