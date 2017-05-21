/*
*
* Tag: Math
* Time: O(1)
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
const int N = 153000;
const int M = 150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int h, t, v, x;

int main(){
    scanf("%d%d%d%d",&h,&t,&v,&x);
    double minans = 0, maxans = 0;
    if (t*x >= h) {
        minans = 0;
        maxans = (double)h/(double)x;
    } else {
        minans = (double)(h - x*t)/(double)(v - x);
        maxans = t;
    }
    printf("%.6lf %.6lf\n",minans, maxans);
    return 0;
}
