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
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;


int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        int ans = INT_MAX;
        for (int i = 0; i < 5; ++ i) {
            int v;
            scanf("%d",&v);
            ans = min(ans, v);
        }
        printf("%d\n",ans);
    }
    return 0;
}
