/*
 *
 * Tag: Geometry
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
const int N = 20000011;
const int M = 1010;
const long long MOD = 1000000007;
const double eps = 1e-10;
pair<int, int> p[2][3];

int crossmulti(pair<int, int> p0, pair<int, int> p1, pair<int, int> p2){
    return (p1.first - p0.first)*(p2.second - p0.second) - (p2.first - p0.first)*(p1.second - p0.second);
}

void solve(){
    int s1 = crossmulti(p[0][0], p[0][1], p[0][2]), s2 = crossmulti(p[1][0], p[1][1], p[1][2]);
    s1 = abs(s1);
    s2 = abs(s2);
    if (s1 == s2) {
        puts("0");
    } else if (s1 > s2) {
        printf("1 %.2lf\n",(double)s1/2.0);
    } else {
        printf("2 %.2lf\n",(double)s2/2.0);
    }
}

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        for (int i = 0; i < 2; ++ i) {
            scanf("%d%d%d%d%d%d",&p[i][0].first, &p[i][0].second,&p[i][1].first,&p[i][1].second,&p[i][2].first,&p[i][2].second);
        }
        solve();
    }
    return 0;
}
