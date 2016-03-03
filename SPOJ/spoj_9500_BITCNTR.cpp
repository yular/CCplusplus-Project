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
const int N = 20;
const int M = 130;
const double eps = 1e-10;
int n;

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        int cnt = 0;
        while (n) {
            if (n&1) {
                ++ cnt;
            }
            n >>= 1;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
