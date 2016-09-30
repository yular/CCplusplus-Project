/*
*
* Tag: DP
* Time: O((n^3)*(2^n))
* Space: O(2^n)
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
const int N = 50;
const int M = 50000;
const long long MOD = 1000000007;
double dp[M];
int n, arr[N], st;
vector<int> v;

double getArea(int a, int b, int c){
    if (a + b <= c) {
        return 0.0;
    }
    double p = (a + b + c)*0.5;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

int main(){
    while (scanf("%d",&n) == 1 && n) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&arr[i]);
        }
        memset(dp, 0, sizeof(dp));
        sort(arr, arr + n);
        v.clear();
        for (int i = 0; i < n - 2; ++ i) {
            for (int j = i + 1; j < n - 1; ++ j) {
                for (int k = j + 1; k < n; ++ k) {
                    st = (1<<i)|(1<<j)|(1<<k);
                    dp[st] = getArea(arr[i], arr[j], arr[k]);
                    if (arr[i] + arr[j] > arr[k])
                        v.push_back(st);
                }
            }
        }
        
        for (int i = 0; i < (1<<n); ++ i) {
            for (int j = 0; j < v.size(); ++ j) {
                if ((i&v[j]))
                    continue;
                dp[(i|v[j])] = max(dp[(i|v[j])], dp[i] + dp[v[j]]);
            }
        }
        
        printf("%.2lf\n",dp[(1<<n)-1]);
    }
    return 0;
}
