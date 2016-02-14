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
//#include <unordered_set>
using namespace std;
const int N = 300;
const int M = 12011;
const int MOD = 10037;
const double dinf = 1e20;
const double eps = 1e-6;
int h, H, L;
double fact = 2.0/3.0;

int main() {
    scanf("%d%d%d",&h,&H,&L);
    if (pow((double)H*h*h/2.0, fact) < h*h) {
        puts("0");
    } else {
        double x = sqrt(pow((double)H*h*h/2.0, fact) - h*h);
        double ans = x*H/2.0/sqrt(h*h + x*x) - x;
        printf("%.6lf\n",ans);
    }
    return 0;
}
