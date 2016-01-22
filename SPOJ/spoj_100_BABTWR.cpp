/*
*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 1010;
const int M = 5020;
int n, m;
int dp[N], x[N], y[N], z[N];

int main() {

    while (scanf("%d",&n)==1 && n) {
        m = 3*n;
        for (int i = 0; i < n; ++ i) {
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);
            x[3*i] = a; y[3*i] = b; z[3*i] = c;
            x[3*i + 1] = a; y[3*i + 1] = c; z[3*i + 1] = b;
            x[3*i + 2] = b; y[3*i + 2] = c; z[3*i + 2] = a;
        }
        
        for (int i = 0; i < m; ++ i) {
            for (int j = i + 1; j < m; ++ j) {
                if ((x[i] < x[j] && y[i] < y[j]) || (x[i] < y[j] && y[i] < x[j])) {
                    swap(x[i], x[j]);
                    swap(y[i], y[j]);
                    swap(z[i], z[j]);
                }
            }
        }
        
        int ans = -1;
        for (int i = 0; i < m; ++ i) {
            dp[i] = z[i];
            
            for (int j = 0; j < i; ++ j) {
                if ((x[i] < x[j] && y[i] < y[j]) || (x[i] < y[j] && y[i] < x[j])) {
                    dp[i] = max(dp[i], dp[j] + z[i]);
                }
            }
            
            ans = max(ans, dp[i]);
        }
        
        printf("%d\n",ans);
        
    }
    return 0;
}
