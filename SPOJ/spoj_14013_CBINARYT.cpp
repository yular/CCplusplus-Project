/*
 *
 * Tag: Bit Manipulation
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
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
long long ans;
int n;

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        ans = 1;
        for (int i = 0; i <= n; ++ i) {
            ans <<= 1;
        }
        printf("Case %d: %lld\n",cas ++,ans-1);
    }
    return 0;
}
