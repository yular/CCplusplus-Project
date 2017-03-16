/*
*
* Tag: Math
* Time: O(nlgm)
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
const int N = 2100002;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, cnt[2], v;

int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        cnt[0] = cnt[1] = 0;
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i ) {
            scanf("%d",&v);
            while (v%2 == 0) {
                ++ cnt[0];
                v /= 2;
            }
            while (v%5 == 0) {
                ++ cnt[1];
                v /= 5;
            }
        }
        printf("%d\n",min(cnt[0], cnt[1]));
    }
    return 0;
}
