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
const int N = 530000;
const int M = 2150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, m, p;

int main(){
    scanf("%d%d%d",&n,&m,&p);
    double ps = (double)(100 - p)/100.0, v = (double)n;
    int ans = 0;
    while (v > m) {
        ++ ans;
        v = v*ps;
    }
    printf("%d\n",ans);
    return 0;
}
