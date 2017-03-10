/*
*
* Tag: Math
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
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, d;
int a[M];

int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        scanf("%d%d%d%d",&a[0],&a[1],&a[2],&n);
        printf("Case %d: ",cas);
        if (a[1] - a[0] == a[2] - a[1]) {
            d = a[1] - a[0];
            printf("%d\n", a[0] + (n - 1)*d);
        } else {
            puts("Error");
        }
    }
    return 0;
}
