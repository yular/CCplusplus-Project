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
const int N = 50200;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, a, p;

int main(){
    scanf("%d",&n);
    p = 0;
    double v = 0.0;
    bool isfind = false;
    for (p = sqrt(n*2); p > 0; -- p) {
        v = (double)n/p - (double)(p - 1)/2;
        if (v == (int)v && v > 0) {
            a = (int)v;
            isfind = true;
            break;
        }
    }
    if (isfind)
        printf("%d %d\n",a,p);
    else
        printf("%d 1\n",n);
    return 0;
}
