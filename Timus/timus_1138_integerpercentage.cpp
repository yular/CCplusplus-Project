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
const int N = 1530000;
const int M = 2150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, s;
int dp[N], ans;

void solve(){
    dp[s] = 1;
    for (int i = s; i < n; ++ i) {
        if (dp[i] == 0) {
            continue;
        }
        for (int p = 1; p <= 100; ++ p) {
            if ((i*p)%100 == 0) {
                int y = i + i*p/100;
                if (y > n) {
                    continue;
                }
                dp[y] = max(dp[y], dp[i] + 1);
                ans = max(ans, dp[y]);
            }
        }
    }
    ans = max(ans, dp[n]);
}

int main(){
    memset(dp, 0, sizeof(dp));
    ans = 0;
    scanf("%d%d",&n,&s);
    if (n < s) {
        swap(s, n);
    }
    solve();
    printf("%d\n",ans);
    return 0;
}
