/*
 *
 * Tag: Math
 * Time: O(n^2)
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
const int N = 1020;
const int M = 10020;
const double eps = 1e-10;
int a, b, c, n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d%d%d",&n,&a,&b,&c);
        long long ans = 0;
        for (int i = 0; i <= min(a, n); ++ i) {
            for (int j = 0; j <= min(n,b); ++ j) {
                int res = n - i - j;
                if (res < 0) {
                    continue;
                }
                ans += (min(res, c) + 1);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
