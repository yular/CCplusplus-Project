/*
*
*
* Tag: DP
* Time: O(mn)
* Space: O(m+n)
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
const int N = 103;
const int M = 510;
//const int INF = 1<<29;
int n, m;
int dp[M];
int v[N], c[N];

void init(){
    for (int i = 1; i <= m; ++ i) {
        dp[i] = -1;
    }
    dp[0] = 0;
    
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d",&c[i],&v[i]);
    }
}

int main() {
//    freopen("/Users/baiyang/Project/CCPP/USACO/USACO/laundro_matt.txt", "r", stdin);
//    freopen("/Users/baiyang/Project/CCPP/USACO/USACO/laundro_matt.out", "w", stdout);
    while (scanf("%d%d",&m,&n)==2 && m && n) {
        init();
        int ansc = m, ansv = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = m; j >= c[i]; -- j) {
                if (dp[j - c[i]] != -1) {
                    dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
                }
                if (dp[j] == ansv) {
                    if (ansc > j) {
                        ansc = j;
                    }
                } else if (dp[j] > ansv) {
                    ansv = dp[j];
                    ansc = j;
                }
            }
        }
        printf("%d %d\n",ansc, ansv);
    }
    return 0;
}
