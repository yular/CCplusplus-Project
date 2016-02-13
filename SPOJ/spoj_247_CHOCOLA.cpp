/*
*
* Tag: Greedy
* Time: O(nlgn)
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
const int N = 1010;
const int M = 101010;
const double eps = 1e-10;
int n, m;
int x[N], y[N];

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&m,&n);
        -- m;
        -- n;
        int sx = 0, sy = 0;
        for (int i = 0; i < m; ++ i) {
            scanf("%d",&x[i]);
            sx += x[i];
        }
        sort(x, x + m);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&y[i]);
            sy += y[i];
        }
        sort(y, y + n);
        int ans = sx + sy;
        for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; ) {
            if (y[j] >= x[i]) {
                ans += sx;
                sy -= y[j];
                -- j;
            } else {
                ans += sy;
                sx -= x[i];
                -- i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
