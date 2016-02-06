/*
*
* Tag: Math
* Time: O(1)
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
#include <unordered_set>
using namespace std;
const int N = 10;
const int M = 205;
const int MOD = 10037;
const double eps = 1e-6;
int line[N];
double WX, WY, WZ, XY, XZ, YZ, sur, rad;

inline double volume(double u, double v, double w, double U, double V, double W){
    
    double u1,v1,w1;
    u1 = v * v + w * w - U * U;
    v1 = w * w + u * u - V * V;
    w1 = u * u + v * v - W * W;
    return sqrt(4.0*u*u*v*v*w*w - u*u*u1*u1 - v*v*v1*v1 - w*w*w1*w1 + u1*v1*w1) / 12.0;
}

inline double surface(double a, double b, double c){
    
    return sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c)) / 4.0;
}

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lf %lf %lf %lf %lf %lf", &WX, &WY, &WZ, &XY, &XZ, &YZ);
        sur = surface(WX, WY, XY) + surface(WX, XZ, WZ) + surface(WY, YZ, WZ) + surface(XY, XZ, YZ);
        rad = volume(WX, WY, WZ, YZ, XZ, XY) * 3.0 / sur;
        printf("%.4lf\n", rad);
    }
    return 0;
}
