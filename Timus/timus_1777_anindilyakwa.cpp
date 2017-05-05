/*
*
* Tag: Implementation
* Time: O(lgn)
* Space: O(n)
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
const int M = 103;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
long long arr[N], tot;
int ans;

int main(){
    tot = 3;
    ans = 1;
    scanf("%lld%lld%lld",&arr[0],&arr[1],&arr[2]);
    while (1) {
        sort(arr, arr + tot);
        long long diff = LLONG_MAX;
        for (int i = 1; i < tot; ++ i) {
            diff = min(diff, arr[i] - arr[i - 1]);
        }
        if (diff == 0) {
            break;
        }
        arr[tot ++] = diff;
        ++ ans;
    }
    printf("%d\n",ans);
    return 0;
}
