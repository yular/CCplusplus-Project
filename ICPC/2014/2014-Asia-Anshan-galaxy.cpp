/*
 ID: ybcabcd1
 LANG: C++
 PROG: fence4
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
const int N = 10000007;
const int M = 502011;
const int MOD = 10037;
const double dinf = 1e20;
const double eps = 1e-6;
const int MAXN = 50010;
const double INF = 1e20;
int n, k, nCase;
long double p[MAXN], sum1[MAXN], sum2[MAXN], ans;

void init() {
    ans = INF;
    sum1[0] = sum2[0] = 0.0;
}

void input() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        double val;
        scanf("%lf", &val);
        p[i] = val;
    }
}

void solve() {
    if (n == k) {
        printf("0.000000000000\n");
        return;
    }
    sort(p+1, p+n+1);
    for (int i = 1; i <= n; i++) {
        sum1[i] = sum1[i-1] + p[i];
        sum2[i] = sum2[i-1] + p[i]*p[i];
    }
    for (int i = 1; i <= k+1; i++) {
        double s1 = sum1[i+n-k-1] - sum1[i-1];
        double s2 = sum2[i+n-k-1] - sum2[i-1];
        double tmp = s2 - s1*s1/(n - k);
        if (tmp < ans) ans = tmp;
    }
    
    printf("%.15Lf\n", ans);
}

int main() {
    scanf("%d", &nCase);
    while (nCase--) {
        init();
        input();
        solve();
    }
    return 0;
}
