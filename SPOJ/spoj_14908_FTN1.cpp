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
const int N = 1000300;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
long long n;


int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",cas++, 2*n-1);
    }
    return 0;
}
