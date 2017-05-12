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
const int N = 53000;
const int M = 50;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int k;
long long n, v, arr[M];

long long solve(){
    long long res = 0;
    for (int i = 0; i < k; ++ i) {
        res += arr[i];
        if (i > 0) {
            res -= n;
        }
        if (res < 0) {
            return 0;
        }
    }
    return res;
}

int main(){
    scanf("%lld%d",&n, &k);
    long long sum = 0;
    for (int i = 0; i < k; ++ i) {
        scanf("%lld",&arr[i]);
    }
    long long ans = solve();
    printf("%lld\n", ans);
    return 0;
}
