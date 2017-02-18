/*
*
* Tag: DP
* Time: O(n^2)
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
const int N = 200030;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, maxval;
int arr[M], dp[M];

int main(){
    scanf("%d",&n);
    maxval = 1;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&arr[i]);
        dp[i] = 1;
    }
    for (int i = 1; i < n; ++ i) {
        for (int j = 0; j < i; ++ j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                maxval = max(dp[i], maxval);
            }
        }
    }
    printf("%d\n",maxval);
    return 0;
}
