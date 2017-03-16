/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(lgn)
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
const int M = 100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int a,b,c;

int gcd(int a, int b){
    return b == 0?a : gcd(b, a%b);
}

int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        scanf("%d/%d",&a,&b);
        c = gcd(a, b);
        printf("Case %d: %d/%d\n",cas,a/c,b/c);
    }
    return 0;
}
