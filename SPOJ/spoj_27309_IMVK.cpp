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
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int ans;
char a[N];

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",&a);
        ans = 0;
        for (int i = 0; a[i]; ++ i) {
            ans = (ans*10 + (a[i] - '0'))%MOD;
        }
        if (ans == 0) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}
