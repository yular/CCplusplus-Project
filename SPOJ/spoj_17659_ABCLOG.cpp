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
const int N = 500;
const int M = 20;
long long n;

int main() {
    while (scanf("%lld",&n) == 1) {
        if (n < 0) {
            break;
        }
        long long ans = 0;
        while (n) {
            if (n&1) {
                ans |= 1;
            }
            n >>= 1;
            if (!n) {
                break;
            }
            ans <<= 1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
