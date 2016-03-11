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
const int N = 2000011;
const int M = 310;
const long long MOD = 1000000007;
const double eps = 1e-10;
long long a, b, an;
int n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld%lld%d",&a,&b,&n);
        an = (n - 1)*(b - a) + a;
        printf("%lld\n",(a + an)*n/2);
    }
    return 0;
}
