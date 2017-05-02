/*
*
* Tag: Implementation
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
const int N = 210;
const int M = 10300;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, k, v;

int main(){
    scanf("%d%d",&n,&k);
    long long ans_unused = 0, ans_surv = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        if (v < k){
            ans_surv += k - v;
        } else if (v > k){
            ans_unused += v - k;
        }
    }
    printf("%lld %lld\n",ans_unused, ans_surv);
    return 0;
}
