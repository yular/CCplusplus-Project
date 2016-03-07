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
const int N = 10000300;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
int n;
int ans;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        ans = 0;
        for (int i = 0; i < 32; ++ i, n >>= 1) {
            if (n&1) {
                ++ ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
