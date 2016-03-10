/*
 *
 * Tag: DP
 * Time: O(n)
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
const int N = 1000200;
const int M = 1030;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        int ans = INT_MIN, sum = 0;
        for (int i = 0; i < n; ++ i) {
            int a;
            scanf("%d",&a);
            sum += a;
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
