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
const int N = 5;
const int M = 210000;
const long long MOD = 1000000007;
const double eps = 1e-10;
const double pi = acos(-1.0);
pair<double,double> o[N];
double r, R;

double intersectArea(const pair<int,int> &o1, const double &r1, const pair<int,int> &o2, const double &r2){
    double area = 0;
    double d = sqrt((o1.first - o2.first)*(o1.first - o2.first) + (o1.second - o2.second)*(o1.second - o2.second));
    if (r1+r2<d+eps)
        return area;
    if (d<fabs(r1-r2)+eps){
        double r=min(r1,r2);
        return pi*r*r;
    }
    double x=(d*d+r1*r1-r2*r2)/(2*d);
    double t1=acos(x/r1);
    double t2=acos((d-x)/r2);
    area = r1*r1*t1+r2*r2*t2-d*r1*sin(t1);
    return area;
}

int main(){
    
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas){
        scanf("%lf%lf",&r,&R);
        for (int i = 0; i < 2; ++ i)
            scanf("%lf%lf",&o[i].first, &o[i].second);
        double ans = 0;
        ans += intersectArea(o[0], R, o[1], R);
        ans -= 2*intersectArea(o[0], R, o[1], r);
        ans += intersectArea(o[0], r, o[1], r);
        printf("Case #%d: %.6lf\n",cas,ans);
    }
    return 0;
}
