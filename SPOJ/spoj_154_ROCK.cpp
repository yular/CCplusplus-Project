/*
*
* Tag: DP
* Time: O(n^2)
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
using namespace std;
const int N = 1010;
const int M = 10001010;
int n;
char rk[N];
int dp[N], cntone[N];

void init(){
    memset(cntone, 0, sizeof(cntone));
    memset(dp, 0, sizeof(dp));
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        scanf("%s",rk);
        init();
        for (int i = 0; i < n; ++ i) {
            cntone[i + 1] = rk[i]=='1'? cntone[i] + 1: cntone[i];
        }
        for (int i = 1; i <= n; ++ i) {
            for (int j = i - 1; j >= 0;  -- j) {
                int curone = cntone[i] - cntone[j] > (i - j)/2?(i - j) : 0;
                dp[i] = max(dp[i], dp[j] + curone);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
