/*
*
* Tag: Brute Force
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
const int N = 33000;
const int M = 103;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, m, a[M], b[M];

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < m; ++ i) {
        scanf("%d",&b[i]);
    }
    sort(a, a + n, greater<int>());
    sort(b, b + m, greater<int>());
    int ans = INT_MAX, sum_a = 0, sum_b = 0, d = min(n, m);
    for (int i = 0; i <= d; ++ i) {
        sum_a = sum_b = 0;
        for (int j = i; j < n; ++ j) {
            sum_a += a[j];
        }
        for (int j = i; j < m; ++ j) {
            sum_b += b[j];
        }
        ans = min(ans, sum_a + sum_b*i);
    }
    printf("%d\n",ans);
    return 0;
}
