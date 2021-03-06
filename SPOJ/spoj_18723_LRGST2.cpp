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
const int N = 120;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
long long a, b;


int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld%lld",&a,&b);
        long long n = a%b;
        printf("Case %d: %lld\n",cas++, a-n);
    }
    return 0;
}
