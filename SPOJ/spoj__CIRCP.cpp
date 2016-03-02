/*
 *
 * Tag: Geometry
 * Time: O(nm)
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
const int N = 1020;
const int M = 10020;
const double eps = 1e-10;
struct cycle{
    int x, y, r;
}c[N];
pair<int, int> p;
int n, m;

int dis(pair<int, int> c, pair<int, int> a){
    return (c.first - a.first)*(c.first - a.first) + (c.second - a.second)*(c.second - a.second);
}

int solve(){
    int res = 0;
    for (int i = 0; i < n; ++ i) {
        pair<int, int> cp = make_pair(c[i].x, c[i].y);
        if (dis(cp, p) < c[i].r) {
            ++ res;
        }
    }
    return res;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].r);
            c[i].r = c[i].r*c[i].r;
        }
        for (int i = 0; i < m; ++ i) {
            int ans = 0;
            scanf("%d%d",&p.first,&p.second);
            ans = solve();
            printf("%d\n",ans);
        }
        if (T) {
            puts("");
        }
    }
    return 0;
}
