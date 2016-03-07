/*
 *
 * Tag: Implementation
 * Time: O(?)
 * Space: O(?)
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 10000300;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
char val[N];
int ans;

void solve(){
    for (int i = 0; val[i]; ++ i) {
        ans += (val[i] - '0');
    }
    while (ans >= 10) {
        int tmp = ans;
        ans = 0;
        while (tmp) {
            ans += (tmp%10);
            tmp /= 10;
        }
    }
}

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",val);
        ans = 0;
        solve();
        printf("%d\n",ans);
    }
    return 0;
}
