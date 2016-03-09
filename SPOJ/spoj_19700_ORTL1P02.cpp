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
const int N = 100010;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
int a;

int main() {
    int ans = INT_MIN;
    for (int i = 0; i < 3; ++ i) {
        scanf("%d",&a);
        ans = max(ans, a);
    }
    printf("%d\n",ans);
    return 0;
}
