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
const int N = 1000200;
const int M = 1030;
const long long MOD = 1000000007;
const double eps = 1e-10;
long long a, b;

int main() {
    scanf("%lld%lld",&a,&b);
    long long res = 0;
    -- a;
    printf("%lld\n",b*(b + 1)/2 - a*(a + 1)/2);
    return 0;
}
