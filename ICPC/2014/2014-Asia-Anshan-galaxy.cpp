/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
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
const int M = 52011;
const int MOD = 10037;
const double dinf = 1e20;
const double eps = 1e-6;
int n, k;
long double p[M], sum1[M], sum2[M], ans;

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
        long double tmp = s2 - s1*s1/(n - k);
        ans = min(ans, tmp);
    }
    
    printf("%.15Lf\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        ans = dinf;
        sum1[0] = sum2[0] = 0.0;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            double val;
            scanf("%lf", &val);
            p[i] = val;
        }
        solve();
    }
    return 0;
}
