/*
*
* Tag: Greedy + DP
* Time: O(1)
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
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int dp[M], arr[6] = {1,2,5,10,20,50}, a[3] = {100, 500, 1000};
int v, id, ans;

void init(){
    for (int i = 1; i < M; ++ i) {
        dp[i] = M;
    }
    dp[0] = 0;
    for (int i = 0; i < 6; ++ i) {
        for (int j = arr[i]; j < M; ++ j) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }
}

int main(){
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&v);
        id = 2;
        ans = 0;
        if(v >= 1000){
            ans += v/1000;
            v %= 1000;
        }
        if(v >= 500){
            ++ ans;
            v -= 500;
        }
        if(v >= 100){
            ans += v/100;
            v %= 100;
        }
        ans += dp[v];
        printf("%d\n",ans);
    }
    return 0;
}
