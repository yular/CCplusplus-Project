/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
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
int n, top, ans, idx, tmpans, i;
int stk[N],blk[N];

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&blk[i]);
        }
        top = i = 0;
        tmpans = ans = 0;
        for (; i < n;) {
            if (top == 0 || blk[i] <= blk[stk[top - 1]]) {
                stk[top ++] = i;
                ++ i;
            }else{
                idx = stk[top - 1];
                -- top;
                tmpans = top == 0?0:(( min(blk[i], blk[stk[top - 1]]) - blk[idx])*(i - stk[top - 1] - 1));
                ans += tmpans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
