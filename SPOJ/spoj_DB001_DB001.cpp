/*
*
* Tag: Math
* Time: O(nlgm)
* Space: O(lgm)
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
int n, a, b, v, ans;

int gcd(int a, int b){
    return a%b == 0?b : gcd(b, a%b);
}

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        int len = 1;
        ans = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&b);
            if (i != 0) {
                if (gcd(a, b) == 1) {
                    ++ len;
                } else {
                    len = 1;
                }
            }
            ans = max(ans, len);
            a = b;
        }
        if ( ans == 1 ) {
            puts("-1");
        } else {
            printf("%d\n",ans);
        }
    }
    return 0;
}
