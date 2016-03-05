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
const int N = 3000200;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
long long n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld",&n);
        if (n <= 0) {
            printf("%lld 1\n",n);
        } else {
            if ((n&(n-1)) == 0) {
                printf("%lld\n",n);
            } else {
                printf("%lld ",n);
                n <<= 1;
                long long m = 1;
                while (m < n) {
                    if (m&n) {
                        n = (n^m);
                    }
                    m <<= 1;
                }
                printf("%lld\n",n);
            }
        }
    }
    return 0;
}
