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
const int N = 200;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
long long n, k, sum, v, tot;

int main(){
    scanf("%lld%lld",&n,&k);
    sum = 0;
    for (int i = 0; i < n - 1; ++ i) {
        scanf("%lld",&v);
        sum += v;
    }
    tot = n*(2*k + n - 1)/2;
    printf("%lld\n",tot - sum);
    return 0;
}
