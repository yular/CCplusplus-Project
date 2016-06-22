/*
 *
 * Tag: DP
 * Time: O((2^n)*n)
 * Space: O(2^n)
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
const int N = 300;
const int M = 2100000;
const long long MOD = 1000000007;
const double eps = 1e-10;
struct tagset{
    int tagval;
    int price;
}tag[N];
int dp[M];
int n, m, t, nm;

void init(){
    for (int i = 0; i < M; ++ i) {
        dp[i] = INT_MAX;
    }
    nm = 0;
    t = 0;
}

int main() {
    init();
    scanf("%d",&n);
    nm += n;
    int u, v, p, tot, id = 0;
    for (int i = 1; i <= n; ++ i, ++ id) {
        scanf("%d",&p);
        tag[id].tagval = (1<<i);
        tag[id].price = p;
        dp[(1<<i)] = min(dp[(1<<i)], p);
    }
    scanf("%d",&m);
    nm += m;
    for (int i = 1; i <= m; ++ i, ++ id) {
        scanf("%d",&p);
        u = 0;
        scanf("%d",&tot);
        for (int j = 0; j < tot; ++ j) {
            scanf("%d",&v);
            u |= (1<<v);
        }
        dp[u] = min(dp[u], p);
        tag[id].tagval = u;
        tag[id].price = p;
    }
    scanf("%d",&tot);
    for (int i = 0; i < tot; ++ i) {
        scanf("%d",&v);
        t |= (1<<v);
    }
    for (int i = 0; i < nm; ++ i) {
        for (int j = 1; j < (1<<(n + 1)); ++ j) {
            if (dp[j] != INT_MAX) {
                dp[(j|tag[i].tagval)] = min(dp[(j|tag[i].tagval)], dp[j] + tag[i].price);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i < (1<<(n + 1)); ++ i) {
        if ((i&t) == t) {
            ans = min(ans, dp[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
