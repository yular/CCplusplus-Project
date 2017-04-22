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
const int N = 10050;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
long long x, y, c;

int main(){
    scanf("%lld%lld%lld",&x,&y,&c);
    if (x + y < c) {
        puts("Impossible");
    } else {
        long long dif = x + y - c;
        if (dif > x) {
            dif -= x;
            x = 0;
        } else {
            x -= dif;
            dif = 0;
        }
        y -= dif;
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
