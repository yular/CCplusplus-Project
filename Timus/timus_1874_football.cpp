/*
*
* Tag: Geometry & Binary Search
* Time: O((x+y)lg(x+y))
* Space: O(1)
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
const int N = 300;
const int M = 12011;
const int MOD = 10037;
const double dinf = 1e20;
const double eps = 1e-6;
double x, y;

double calarea(double z){
    double p = (x + y + z)/2.0;
    return z*z/4.0 + sqrt(p*(p -x)*(p - y)*(p - z));
}

int main() {
    scanf("%lf%lf",&x,&y);
    double ans = 0;
    double l = 0.0, r = (x + y);
    while (fabs(r - l) > eps) {
        double mid1 = (l + r)/2.0;
        double mid2 = (r + mid1)/2.0;
        double s1 = calarea(mid1), s2 = calarea(mid2);
        if (s1 > s2) {
            r = mid2;
        } else {
            l = mid1;
        }
        ans = max(ans, s1);
    }
    printf("%.9lf\n",ans);
    return 0;
}
