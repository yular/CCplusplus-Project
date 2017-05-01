/*
*
* Tag: Implementation
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
const int N = 210;
const int M = 10300;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int r, b, y, n;
char col[N];

int main(){
    scanf("%d%d%d",&b,&r,&y);
    scanf("%d",&n);
    int ans = 1;
    for (int i = 0; i < n; ++ i) {
        scanf("%s",col);
        if (col[0] == 'B')
            ans *= b;
        else if (col[0] == 'R')
            ans *= r;
        else
            ans *= y;
    }
    printf("%d\n",ans);
    return 0;
}
