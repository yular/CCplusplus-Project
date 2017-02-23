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
const int N = 2000200;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
long long a, b;
char sa[M], sb[M];

long long getInt(char a[]){
    long long res = 0, mask = 1;
    int len = strlen(a);
    for (int i = len - 1; i >= 0; -- i) {
        if (a[i] == '1') {
            res |= mask;
        }
        mask <<= 1;
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas ) {
        scanf("%s%s",sa,sb);
        a = getInt(sa);
        b = getInt(sb);
        if (b != 0 && a%b == 0)
            printf("Case %d: YES\n",cas);
        else
            printf("Case %d: NO\n",cas);
    }
    return 0;
}
