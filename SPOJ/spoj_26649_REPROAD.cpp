/*
*
* Tag: Greedy
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
const int N = 10010;
const int M = 50000;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
int n, k;
int rd[N];

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&k);
        for (int i = 0; i < n; ++ i)
            scanf("%d",&rd[i]);
        int cntk = 0, fidx = 0, bidx = 0, ans = 0;
        for (; fidx < n; ++ fidx) {
            if (rd[fidx] == 0) {
                ++ cntk;
            }
            while (cntk > k) {
                if (rd[bidx] == 0) {
                    -- cntk;
                }
                ++ bidx;
            }
            ans = max(ans, fidx - bidx + 1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
