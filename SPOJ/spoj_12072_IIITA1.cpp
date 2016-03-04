/*
 *
 * Tag: Bit Manipulation
 * Time: O(lgn)
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
const int N = 100020;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
long long a, b;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld%lld",&a,&b);
        long long c = a^b;
        int cnt = 0;
        while (c) {
            if (c&1) {
                ++ cnt;
            }
            c >>= 1;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
