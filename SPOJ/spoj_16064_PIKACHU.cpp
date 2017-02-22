/*
*
* Tag: Implementation
* Time: O(n^2)
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
const int N = 200;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, ans;
int arr[N];

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&arr[i]);
        }
        ans = 0;
        for (int i = n - 1; i >= 0; -- i) {
            for (int j = i + 1; j < n; ++ j) {
                if (arr[i] < arr[j]) {
                    ++ ans;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
