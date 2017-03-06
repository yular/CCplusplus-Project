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
const int N = 10002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, u, v;

int main(){
    scanf("%d",&n);
    int cnt_large = 0, cnt_divfive = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        if (v%5 == 0) {
            ++ cnt_divfive;
        }
        if (i == 0) {
            u = v;
        } else {
            cnt_large += (v > u);
        }
    }
    printf("%d %d\n",cnt_large,cnt_divfive);
    return 0;
}
