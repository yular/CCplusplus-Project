/*
 *
 * Tag: Geometry
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
const int N = 30010;
const int M = 101010;
const double eps = 1e-10;
int n;
pair<int, int> p;

int dist(){
    return (p.first*p.first + p.second*p.second);
}

int main() {
    int T, t = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        int ans = 0, dis = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d",&p.first,&p.second);
            int tmpdis = dist();
            if (dis < tmpdis) {
                dis = tmpdis;
                ans = i + 1;
            }
        }
        printf("Case %d: %d\n",t++, ans);
        if (T) {
            puts("");
        }
    }
    return 0;
}
