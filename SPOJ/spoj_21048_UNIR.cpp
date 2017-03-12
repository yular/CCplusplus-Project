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
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
long long p[4];

double dist(){
    return sqrt((p[2] - p[0])*(p[2] - p[0]) + (p[3] - p[1])*(p[3] - p[1]));
}

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        for (int i = 0; i < 4; ++ i) {
            scanf("%lld",&p[i]);
        }
        printf("%.6lf\n",dist()/2.0);
    }
    return 0;
}
