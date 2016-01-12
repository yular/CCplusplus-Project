/*
*
* Tag: Math & Geometry
* Time: O(n)
* Space: O(n)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 400;
const int M = 1000020;
const int INF = 1<<29;
struct poly {
    int num;
    pair<int, int> pnt[M];
}p;
int n;

long long xmult(pair<int,int> p, pair<int, int> q){
    return p.first*q.second - p.second*q.first;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&p.num);
        for (int i = 0; i < p.num; ++ i) {
            scanf("%d%d",&p.pnt[i].first,&p.pnt[i].second);
        }
        long long gx = 0, gy = 0;
        double area = 0;
        for (int i = 0; i < p.num; ++ i) {
            area += (double)xmult(p.pnt[i], p.pnt[(i + 1)%p.num]);
            gx += xmult(p.pnt[i], p.pnt[(i + 1)%p.num])*(p.pnt[i].first + p.pnt[(i + 1)%p.num].first);
            gy += xmult(p.pnt[i], p.pnt[(i + 1)%p.num])*(p.pnt[i].second + p.pnt[(i + 1)%p.num].second);
        }
        area /= 2.0;
        double x = (double)gx/(6.0*area), y = (double)gy/(6.0*area);
        printf("%.2lf %.2lf\n",x,y);
    }
    return 0;
}
