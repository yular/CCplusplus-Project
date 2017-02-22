/*
*
* Tag: DP
* Time: O(nk)
* Space: O(k)
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
const int N = 100200;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, k;
int arr[M], dp[N];

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&k);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&arr[i]);
        }
        for (int i = 1; i <= k; ++ i) {
            dp[i] = n + 1;
        }
        dp[0] = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = k; j >= arr[i]; -- j) {
                dp[j] = min(dp[j - arr[i]] + 1, dp[j]);
            }
        }
        if (dp[k] >= n + 1) {
            puts("impossible");
        } else {
            printf("%d\n",dp[k]);
        }
    }
    return 0;
}
