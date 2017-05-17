/*
*
* Tag: Math
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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 1530000;
const int M = 2150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
long long r, w, h, ans, q, p;


int main(){
    scanf("%lld",&r);
    w = r;
    h = 0;
    q = r*r;
    while (h < r) {
        p = q - h*h;
        while (w*w >= p && w >= 0) {
            -- w;
        }
        ans += (w + 1);
        ++ h;
    }
    printf("%lld\n",4*ans);
    return 0;
}
