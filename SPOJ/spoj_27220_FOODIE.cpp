/*
*
* Tag: DP
* Time: O(kn)
* Space: O(max(k,n))
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
const int N = 20002;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
bool dp[N];
int fd[N], n, r, v, k, m, sum;

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&k);
        m = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&r);
            sum = 0;
            for (int j = 0; j < r; ++ j) {
                scanf("%d",&v);
                sum += v;
            }
            if (sum <= k) {
                fd[m ++] = sum;
            }
        }
        dp[0] = 1;
        int ans = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = k; j >= fd[i]; -- j) {
                dp[j] |= dp[j - fd[i]];
                if(dp[j])
                    ans = max(ans, j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
