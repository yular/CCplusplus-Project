/*
*
* Tag: Math
* Time: O(k)
* Space: O(1)
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 1010;
const int M = 100100;
//const int INF = 1<<29;
int n, k;

int main() {

    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&k);
        -- n;
        -- k;
        if (k > n - k) {
            k = n - k;
        }
        long long ans = 1;
        for (int i  = 0; i < k; ++ i) {
            ans = ans*(n - i)/(i + 1);
        }
        printf("%lld\n",ans);
    }
    return 0;
    
}
