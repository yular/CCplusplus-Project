/*
 *
 * Tag: Geometry
 * Time: O(m)
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
const int N = 310;
const int M = 101010;
const double eps = 1e-10;
int n;
char t[N];
int p[N];


int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        int lx = INT_MAX, ly = INT_MAX, rx = INT_MIN, ry = INT_MIN;
        for (int i = 0; i < n; ++ i) {
            scanf("%s",t);
            if (t[0] == 'p') {
                scanf("%d%d",&p[0],&p[1]);
                lx = min(lx, p[0]);
                ly = min(ly, p[1]);
                rx = max(rx, p[0]);
                ry = max(ry, p[1]);
            } else if(t[0] == 'c') {
                scanf("%d%d%d",&p[0],&p[1],&p[2]);
                lx = min(lx, p[0] - p[2]);
                ly = min(ly, p[1] - p[2]);
                rx = max(rx, p[0] + p[2]);
                ry = max(ry, p[1] + p[2]);
            } else {
                scanf("%d%d%d%d",&p[0],&p[1],&p[2],&p[3]);
                lx = min(lx, p[0]);
                lx = min(lx, p[2]);
                ly = min(ly, p[1]);
                ly = min(ly, p[3]);
                rx = max(rx, p[0]);
                rx = max(rx, p[2]);
                ry = max(ry, p[1]);
                ry = max(ry, p[3]);
            }
        }
        printf("%d %d %d %d\n",lx,ly,rx,ry);
    }
    return 0;
}
