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
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
long long ans;
int n;

void solve(){
    while (n) {
        ans *= 10;
        ans += n%10;
        n /= 10;
    }
}

int main() {
    while (scanf("%d",&n) == 1) {
        ans = 0;
        solve();
        printf("%lld\n",ans);
    }
    return 0;
}
