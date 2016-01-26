/*
*
* Tag: DP
* Time: O(NF)
* Space: O(F)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 610;
const int M = 10100;
//const int INF = 1<<29;
long long dp[M];
int p[N], w[N];
int n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        int e, f;
        scanf("%d%d",&e,&f);
        f-=e;
        for (int i = 1; i <= f; ++ i) {
            dp[i] = LLONG_MAX;
        }
        dp[0] = 0;
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d",&p[i],&w[i]);
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = w[i]; j <= f; ++ j) {
                if (dp[j - w[i]] != LLONG_MAX) {
                    dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
                }
            }
        }
        if (dp[f] == LLONG_MAX) {
            puts("This is impossible.");
        } else {
            printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[f]);
        }
    }
    return 0;
}
