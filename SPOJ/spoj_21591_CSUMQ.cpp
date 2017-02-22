/*
*
* Tag: Math
* Time: O(n)
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
const int N = 100200;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, q,l, r;
long long sum[N], ans;

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%lld",&sum[i]);
        if (i > 0) {
            sum[i] += sum[i - 1];
        }
    }
    scanf("%d",&q);
    while (q --) {
        scanf("%d%d",&l,&r);
        if (l > r) {
            puts("0");
        } else {
            ans = sum[r];
            if (l > 0) {
                ans -= sum[l - 1];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
