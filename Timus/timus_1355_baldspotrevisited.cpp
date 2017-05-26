/*
*
* Tag: Math
* Time: O(lgn)
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
const int N = 15;
const int M = 150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int a, b;

int calc(int v){
    int res = 0;
    while (1) {
        int i = 2;
        for (; i*i <= v; ++ i) {
            if (v%i == 0) {
                while (v%i == 0) {
                    ++ res;
                    v /= i;
                }
            }
        }
        if (i*i > v) {
            if (v > 1) {
                ++ res;
            }
            break;
        }
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&a,&b);
        if (b % a != 0) {
            puts("0");
            continue;
        }
        if (a == b) {
            puts("1");
            continue;
        }
        int ans = 1 + calc(b/a);
        printf("%d\n",ans);
    }
    return 0;
}
