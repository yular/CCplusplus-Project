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
const int N = 2000200;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, k, v, sum, ans;

int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        scanf("%d%d",&n,&k);
        sum = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&v);
            sum += v;
        }
        printf("Case %d: %d\n",cas,k*(n+1)-sum);
    }
    return 0;
}
