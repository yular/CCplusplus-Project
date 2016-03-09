/*
 *
 * Tag: Implementation
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 1200;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n, m;
int a[N];


int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        int ans = 1;
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&a[i]);
        }
        int tmpcnt = 1;
        for (int  i = 1; i < n; ++ i) {
            if (a[i] < a[i - 1]) {
                ++ tmpcnt;
            } else {
                tmpcnt = 1;
            }
            ans = max(ans, tmpcnt);
        }
        printf("Case #%d: %d\n",cas++, ans);
    }
    return 0;
}
