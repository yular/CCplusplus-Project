/*
*
* Tag: Math
* Time: O(n^2*lgm)
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
const int N = 2100002;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int a[3], cnt;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        for (int i = 0; i < 3; ++ i ) {
            scanf("%d",&a[i]);
        }
        cnt = 0;
        for (int i = 0; i < 3; ++ i) {
            for (int j = i + 1; j < 3; ++ j) {
                if (gcd(a[i], a[j]) == 1) {
                    ++ cnt;
                }
            }
        }
        printf("Case %d: %d DEGREE\n",cas,cnt);
    }
    return 0;
}
