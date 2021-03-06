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
const int N = 110;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
int a[3];

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        sort(a, a + 3);
        if (a[0] + a[1] == a[2]) {
            puts("OK");
        } else {
            puts("NOK");
        }
    }
    return 0;
}
