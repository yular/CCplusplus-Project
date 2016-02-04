/*
*
* Tag: DP
* Time:
* Space:
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
const int N = 1500;
const int M = 1000010;
int n;
char mp[N][N], ans;
int dp[N][N];
int maxcnt;

void print(){
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            printf("%d ",dp[i][j]);
        }
        puts("");
    }
    puts("");
}

void solve(char targ){
    memset(dp, 0, sizeof(dp));
    for (int i = 0;  i < n;  ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (j > 0) {
                if (mp[i][j] == mp[i][j - 1] && mp[i][j] == targ) {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
            }
            if (!dp[i][j] && mp[i][j] == targ) {
                ++ dp[i][j];
            }
            if (maxcnt < dp[i][j]) {
                ans = targ;
                maxcnt = dp[i][j];
            } else if (maxcnt == dp[i][j]){
                if (ans != targ) {
                    ans = '?';
                }
            }
        }
    }
 //   print();
    
    memset(dp, 0, sizeof(dp));
    for (int i = 0;  i < n;  ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (j > 0) {
                if (mp[j][i] == mp[j - 1][i] && mp[j][i] == targ) {
                    dp[j][i] = dp[j - 1][i] + 1;
                }
            }
            if (!dp[j][i] && mp[j][i] == targ) {
                ++ dp[j][i];
            }
            if (maxcnt < dp[j][i]) {
                ans = targ;
                maxcnt = dp[j][i];
            } else if (maxcnt == dp[j][i]){
                if (ans != targ) {
                    ans = '?';
                }
            }
        }
    }
//    print();
    
    memset(dp, 0, sizeof(dp));
    for (int i = 0;  i < n;  ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (j > 0 && i > 0) {
                if (mp[i][j] == mp[i - 1][j - 1] && mp[i][j] == targ) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
            if (!dp[i][j] && mp[i][j] == targ) {
                ++ dp[i][j];
            }
            if (maxcnt < dp[i][j]) {
                ans = targ;
                maxcnt = dp[i][j];
            } else if (maxcnt == dp[i][j]){
                if (ans != targ) {
                    ans = '?';
                }
            }
        }
    }
//    print();
    
    memset(dp, 0, sizeof(dp));
    for (int i = 0;  i < n;  ++ i) {
        for (int j = n - 1; j >= 0; -- j) {
            if (i > 0 && j < n - 1) {
                if (mp[i][j] == mp[i - 1][j + 1] && mp[i][j] == targ) {
                    dp[i][j] = dp[i - 1][j + 1] + 1;
                }
            }
            if (!dp[i][j] && mp[i][j] == targ) {
                ++ dp[i][j];
            }
            if (maxcnt < dp[i][j]) {
                ans = targ;
                maxcnt = dp[i][j];
            } else if (maxcnt == dp[i][j]){
                if (ans != targ) {
                    ans = '?';
                }
            }
        }
    }
//    print();
}

int main() {
    //    freopen("/Users/baiyang/Project/CCPP/USACO/USACO/laundro_matt.txt", "r", stdin);
    //    freopen("/Users/baiyang/Project/CCPP/USACO/USACO/laundro_matt.out", "w", stdout);
    while (scanf("%d",&n) == 1) {
    //    printf("n = %d\n",n);
        for (int i = 0; i < n; ++ i) {
            scanf("%s",mp[i]);
      //      puts(mp[i]);
        }
        ans = 0;
        maxcnt = 0;
        solve('S');
    //    printf("%c\n",ans);
   //     printf("%d\n",maxcnt);
        solve('s');
        printf("%c\n",ans);
        printf("%d\n",maxcnt);
    }
    return 0;
}

