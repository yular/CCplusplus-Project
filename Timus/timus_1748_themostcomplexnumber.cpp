/*
*
* Tag: Number Theory
* Time: O(2^m)
* Space: O(m)
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
const int M = 55;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int prime[M], num;
bool isprime[M + 1];
long long ans, maxcnt, n;

void init(){
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    num = 0;
    for (int i = 2; i <= M; ++ i) {
        if (!isprime[i]) {
            continue;
        }
        prime[num ++] = i;
        for (int j = i*i; j <= M && j >= 0; j += i) {
            isprime[j] = false;
        }
    }
}

void dfs(int start, int upbnd, long long val, long long cur, long long cnt){
    if (cnt > maxcnt || (cnt == maxcnt && cur < ans )) {
        maxcnt = cnt;
        ans = cur;
    }
    if ((start >= 15) || (val < prime[start])) {
        return ;
    }
    for (long long i = prime[start], j = 1; i <= val && j <= upbnd; i*=prime[start], ++ j) {
        dfs(start + 1, j, val/i, cur*i, cnt*(j + 1));
    }
}

int main(){
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld",&n);
        maxcnt = 0;
        ans = n;
        dfs(0, 64, n, 1, 1);
        printf("%lld %lld\n",ans, maxcnt);
    }
    return 0;
}
