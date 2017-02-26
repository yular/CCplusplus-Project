/*
*
* Tag: Implementation
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
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
char a[M], b[M];
int c[M], len;

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s%s",a,b);
        len = 0;
        int ai = strlen(a) - 1, bi = strlen(b) - 1, ci = 0;
        for (; ai >= 0 && bi >= 0; -- ai, -- bi) {
            c[ci ++] = (a[ai] - '0') + (b[bi] - '0');
        }
        for (int i = ci - 1; i >= 0; -- i) {
            printf("%d",c[i]);
        }
        puts("");
    }
    return 0;
}
