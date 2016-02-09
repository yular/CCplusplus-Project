/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
const int N = 10000007;
const int M = 100;
const int MOD = 10037;
const double eps = 1e-6;
char dict[6][7] = {"out","output","puton","in","input","one"};
int len[] = {3,6,5,2,5,3};
char str[N + 1];
bool dp[N + 1];
int m;

void init(){
    memset(dp, 0, sizeof(dp));
}

void solve(){
    dp[0] = 1;
    for (int i = 0; i < m; ++ i) {
        if (dp[i]) {
            for (int j = 0; j < 6; ++ j) {
                if (i + len[j] <= m) {
                    bool ismatch = true;
                    for (int k = 0; k < len[j]; ++ k) {
                        if (str[i + k] != dict[j][k]) {
                            ismatch = false;
                            break;
                        }
                    }
                    
                    if (ismatch) {
                        dp[i + len[j]] = 1;
                    }
                }
            }
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while (T --) {
        init();
        gets(str);
        m = strlen(str);
        solve();
        if (dp[m]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
