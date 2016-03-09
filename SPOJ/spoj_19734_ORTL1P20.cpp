/*
 *
 * Tag: Implementation
 * Time: O(n)
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
const int N = 100010;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
int a, n;

int main() {
    int ans = INT_MAX, cnt = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&a);
        if (ans > a) {
            ans = a;
            cnt = 1;
        } else if (ans == a) {
            ++ cnt;
        }
    }
    printf("%d\n",ans);
    printf("%d\n",cnt);
    return 0;
}
