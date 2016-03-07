/*
 *
 * Tag: Implementation
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
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
long long minans, maxans;
long long arr[M];
int n;


int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld%lld%lld",&arr[0],&arr[1],&arr[2]);
        sort(arr, arr + 3);
        minans = LLONG_MAX;
        maxans = LLONG_MIN;
        long long val = 0;
        val = (arr[0] + arr[1])*arr[2];
        minans = min(minans, val);
        maxans = max(maxans, val);
        val = arr[0] + arr[1]*arr[2];
        minans = min(minans, val);
        maxans = max(maxans, val);
        val = arr[0] * arr[1] + arr[2];
        minans = min(minans, val);
        maxans = max(maxans, val);
        val = arr[0] * (arr[1] + arr[2]);
        minans = min(minans, val);
        maxans = max(maxans, val);
        printf("%lld %lld\n",minans,maxans);
    }
    return 0;
}
