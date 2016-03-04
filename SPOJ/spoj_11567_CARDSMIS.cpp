/*
 *
 * Tag: Math
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
const int N = 120010;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
int n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        int ans = n*(n + 1)/2;
        int sum = 0;
        for (int i = 1; i < n; ++ i) {
            int v;
            scanf("%d",&v);
            sum += v;
        }
        ans -= sum;
        printf("%d\n",ans);
    }
    return 0;
}
