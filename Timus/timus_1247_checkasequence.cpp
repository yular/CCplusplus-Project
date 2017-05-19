/*
*
* Tag: DP
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
const int N = 153000;
const int M = 150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int sum, n, s, v;

int main(){
    scanf("%d%d",&s,&n);
    int tmpsum = 0;
    sum = INT_MIN;
    for (int i = 0; i < s; ++ i) {
        scanf("%d",&v);
        tmpsum += (v - 1);
        sum = max(sum, tmpsum);
        if (tmpsum < 0) {
            tmpsum = 0;
        }
    }
    if (sum <= n) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
