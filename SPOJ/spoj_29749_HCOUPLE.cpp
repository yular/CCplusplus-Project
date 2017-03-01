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
const int N = 2000200;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
char s[M];
int sum;

int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas ) {
        scanf("%s",s);
        sum = 0;
        for (int i = 0; s[i]; ++ i) {
            sum += s[i];
        }
        printf("Case %d: ",cas);
        if (sum%3 == 0) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
