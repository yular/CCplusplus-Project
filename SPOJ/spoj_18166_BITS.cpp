/*
 *
 * Tag: Bit Manipulation
 * Time: O(nlgn)
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
#include <unordered_set>
using namespace std;
const int N = 1200;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n, m;
int dp[N];

int cntBit(int v){
    int res = 0;
    while (v) {
        if (v&1) {
            ++ res;
        }
        v >>= 1;
    }
    return res;
}

void init(){
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 1010; ++ i) {
        dp[i] = cntBit(i);
        dp[i] += dp[i - 1];
    }
}

int main() {
    init();
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
