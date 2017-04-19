/*
*
* Tag: Math
* Time: O(lgv)
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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 10050;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
double v, a, k;

double calc(){
    return v*sin(a*PI/90.0)/10.0;
}

int main(){
    scanf("%lf%lf%lf",&v,&a,&k);
    v = v*v;
    double ans = 0;
    while (1) {
        ans += calc();
        v /= k;
        if (v < eps) {
            break;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}
