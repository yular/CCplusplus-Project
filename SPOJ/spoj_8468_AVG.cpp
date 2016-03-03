/*
 *
 * Tag: Math
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
const int N = 10020;
const int M = 120;
const double eps = 1e-10;
int ans, n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        int a;
        ans = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&a);
            ans += a;
        }
        printf("%d\n",ans/n);
    }
    return 0;
}
