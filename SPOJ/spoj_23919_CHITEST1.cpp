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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 310;
const int M = 101010;
const double eps = 1e-10;
double a, b;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lf%lf",&a,&b);
        printf("%.7lf\n",a+b);
    }
    return 0;
}
