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
const int N = 15;
const int M = 150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
double n, m, ans;

int main(){
    scanf("%lf%lf",&n,&m);
    ans = 0;
    int i = 1;
    while (n - m/(2*i - 1) > 0) {
        ans += m;
        n -= m/(2*i - 1);
        ++ i;
    }
    ans += n*(2*i - 1);
    printf("%.0lf\n",ceil(ans));
    return 0;
}
