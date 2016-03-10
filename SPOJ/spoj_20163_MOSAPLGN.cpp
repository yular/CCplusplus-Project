/*
 *
 * Tag: Implementation
 * Time: O(1)
 * Space: O(1)
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
const int N = 100010;
const int M = 130;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n;
double ang;


int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        double sum = (n - 2)*180, ans = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%lf",&ang);
            ans += ang;
        }
        if (fabs(ans - sum) < eps) {
            puts("POSSIBLE");
        } else {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
