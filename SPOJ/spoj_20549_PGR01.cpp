/*
 *
 * Tag: Math
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
const int N = 500;
const int M = 20;
const double eps = 1e-10;
int n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        long long res = 1, ans = 0, fact = 2*n - 1;
        for (int i = 1; i < n; ++ i) {
            res *= 3;
        }
        ans = res*fact;
        printf("%lld\n",ans);
    }
    return 0;
}
