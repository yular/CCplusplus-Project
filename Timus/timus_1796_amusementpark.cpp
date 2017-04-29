/*
*
* Tag: Math
* Time: O(k)
* Space: O(k)
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
const int N = 200;
const int M = 10300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int arr[M], n, k;

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&k);
        int m = n/k, p = n%k;
        long long ans = 0;
        for (int i = 0; i < k; ++ i) {
            arr[i] = m;
            if (i < p) {
                ++ arr[i];
            }
        }
        int sum = 0;
        for (int i = 0; i < k; ++ i) {
            sum += arr[i];
            ans += arr[i]*(n - sum);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
