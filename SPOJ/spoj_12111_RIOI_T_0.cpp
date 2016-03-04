/*
 *
 * Tag: Greedy (Sort)
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
const int N = 100020;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
long long a[N], b[N];
int n;

bool cmp(const long long &a, const long long &b){
    return b < a;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%lld",&a[i]);
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%lld",&b[i]);
        }
        sort(a, a + n);
        sort(b, b + n, cmp);
        long long ans = 0;
        for (int i = 0; i < n; ++ i) {
            ans += a[i]*b[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
