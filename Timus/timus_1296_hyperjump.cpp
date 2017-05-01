/*
*
* Tag: DP
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
const int N = 200;
const int M = 10300;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n;
long long sum, ans, v;

int main(){
    scanf("%d",&n);
    ans = LLONG_MIN;
    sum = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%lld",&v);
        sum += v;
        ans = max(ans, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    printf("%lld\n",ans < 0?0:ans);
    return 0;
}
