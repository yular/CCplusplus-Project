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
const int N = 33000;
const int M = 50;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, dp[M][M], ans[M];

void init(){
    memset(ans, 0, sizeof(ans));
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= 10; ++ i) {
        for (int j = 1; j <= i; ++ j) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])*j;
            ans[i] += dp[i][j];
        }
    }
}

int main(){
    init();
    while(scanf("%d",&n) == 1){
        if(n == -1)
            break;
        printf("%d\n",ans[n]);
    }
    return 0;
}
