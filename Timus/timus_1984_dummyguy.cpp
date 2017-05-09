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
const int N = 33000;
const int M = 550;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n;

double solve(){
    if (n == 1) {
        return 1;
    }
    double res = 1/sin(PI/(double)n);
    res += 1.0;
    return res;
}

int main(){
    scanf("%d",&n);
    double ans = solve();
    printf("%.6lf\n",ans);
    return 0;
}
