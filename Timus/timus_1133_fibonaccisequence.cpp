/*
*
* Tag: Binary Search
* Time: O(lgm)
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
pair<int, long long> a, b;

int main(){
    scanf("%d%lld%d%lld%d",&a.first,&a.second,&b.first,&b.second,&n);
    if (a.first > b.first) {
        swap(a, b);
    }
    long long l = -INF, r = INF, mid = 0, f0 = 0, f1 = 0, f2 = 0;
    while (l <= r) {
        mid = (l + r)>>1;
        f0 = a.second, f1 = mid;
        for (long long i = a.first + 2; i <= b.first; ++ i) {
            f2 = f0 + f1;
            f0 = f1, f1 = f2;
            if (f1 > INF || f1 < -INF)
                break;
        }
        if (f1 == b.second)
            break;
        else if (f1 > b.second)
            r = mid - 1;
        else
            l = mid + 1;
    }
    long long ans = 0;
    f0 = a.second, f1 = mid, f2 = r;
    if (n >= a.first + 1) {
        for (long long i = a.first + 2; i <= n; ++ i) {
            f2 = f1 + f0;
            f0 = f1, f1 = f2;
        }
        ans = f1;
    } else {
        for (long long i = a.first - 1; i >= n; -- i) {
            f2 = f1 - f0;
            f1 = f0, f0 = f2;
        }
        ans = f0;
    }
    printf("%lld\n",ans);
    return 0;
}
