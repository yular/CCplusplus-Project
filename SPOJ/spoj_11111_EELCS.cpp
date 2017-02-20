/*
*
* Tag: DP
* Time: O(n^2)
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
const int N = 200;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
char s[N], t[N];
int dp[M][M];
int n, m;

int main(){
    scanf("%s%s",s,t);
    //s[0] = 1, t[0] = 1;
    memset(dp, 0, sizeof(dp));
    n = strlen(s);
    m = strlen(t);
    for (int i = 0; i <= n; ++ i) {
        for (int j = 0; j <= m; ++ j) {
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            } else if (s[i - 1] == t[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                //dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
