/*
 *
 * Tag: Math
 * Time: O(lgy)
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
const int N = 50010;
const int M = 20;
const double eps = 1e-10;
long long x, y, n;

long long solve(){
    long long res = 1;
    while (y) {
        if (y&1) {
            res = (res*x)%n;
        }
        y >>= 1;
        x = (x*x)%n;
    }
    return res;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld%lld%lld",&x,&y,&n);
        long long ans = solve();
        printf("%lld\n",ans);
    }
    return 0;
}
