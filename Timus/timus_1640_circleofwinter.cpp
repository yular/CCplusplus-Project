/*
*
* Tag: Geometry
* Time: O(n)
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
pair<double, double> pnt, cpnt;
double r;
int n;

double dis(pair<double, double> &o, pair<double, double> &p){
    return sqrt((o.first - p.first)*(o.first - p.first) + (o.second - p.second)*(o.second - p.second));
}

int main() {
    scanf("%d",&n);
    cpnt.first = cpnt.second = 1005.0;
    r = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%lf%lf",&pnt.first,&pnt.second);
        r = max(r, dis(cpnt, pnt));
    }
    printf("%.9lf %.9lf %.9lf\n",cpnt.first,cpnt.second,r);
    return 0;
}
