/*
*
* Tag: Math
* Time: O(lgn)
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
const int N = 200200;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n;
long long ans;

int main(){
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; ++ cas) {
        ans = 0;
        scanf("%d",&n);
        for (int i = 7; i < n; i += 7) {
            ans += i;
        }
        for (int i = 13; i < n; i += 13) {
            ans += i;
        }
        for (int i = 91; i < n; i += 91) {
            ans -= i;
        }
        printf("Case %d: %lld\n",cas, ans);
    }
    return 0;
}
