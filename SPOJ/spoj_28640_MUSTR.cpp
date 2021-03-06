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
const int N = 200200;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n;

long long cal(){
    long long res = 0, multi = 1;
    for (int i = 0; i < n; ++ i) {
        res += multi;
        multi *= -2;
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        long long ans = cal();
        if (ans < 0) {
            ans = -ans;
            printf("%lld L\n",ans);
        } else {
            printf("%lld R\n",ans);
        }
    }
    return 0;
}
