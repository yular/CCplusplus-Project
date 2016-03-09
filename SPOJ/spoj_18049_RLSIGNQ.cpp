/*
 *
 * Tag: Implementation
 * Time: O(n)
 * Space: O(n)
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
int n, m;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        int sum = 0;
        for (int i = 0; i < n; ++ i) {
            int v;
            scanf("%d",&v);
            sum += v;
        }
        if (sum%m == 0) {
            printf("%d\n",sum/m);
        } else {
            printf("%d\n",sum/m + 1);
        }
    }
    return 0;
}
