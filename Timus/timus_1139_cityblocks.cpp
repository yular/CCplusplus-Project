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
const int N = 210;
const int M = 10300;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, m;

int gcd(int a, int b){
    return b == 0? a : gcd(b, a%b);
}

int main(){
    scanf("%d%d",&n,&m);
    -- n; -- m;
    printf("%d\n", n + m - gcd(n, m));
    return 0;
}
