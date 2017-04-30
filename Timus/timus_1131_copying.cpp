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
const int N = 200;
const int M = 10300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, k, ans;

int main(){
    scanf("%d%d",&n,&k);
    for (ans = 0; (1<<ans) < k && (1<<ans) < n; ++ ans);
    if ((1 << ans) < n) {
        ans += (n - (1<<ans) - 1)/k + 1;
    }
    printf("%d\n",ans);
    return 0;
}
