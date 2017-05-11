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
const int N = 33000;
const int M = 50;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n;
double v, a0, an;

int main(){
    scanf("%d",&n);
    scanf("%lf%lf",&a0,&an);
    double sum = 0, tmpsum = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%lf",&v);
        tmpsum += v;
        sum += tmpsum;
    }
    printf("%.2lf\n",(an + n*a0 - 2*sum)/(n + 1));
    return 0;
}
