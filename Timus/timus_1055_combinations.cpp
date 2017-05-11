/*
*
* Tag: Number Theory
* Time: O(nlgn)
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
const int N = 53000;
const int M = 50;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int num, prime[N], n, m, pn[N], pm[N];
bool notprime[N];

void init(){
    num = 0;
    for (int i = 2; i <= 50010; ++ i) {
        if (!notprime[i]) {
            prime[num ++] = i;
        }
        for (int j = 0; j < num && i*prime[j] <= 50010; ++ j) {
            notprime[i*prime[j]] = 1;
            if (!(i%prime[j])) {
                break;
            }
        }
    }
    memset(pn, 0, sizeof(pn));
    memset(pm, 0, sizeof(pm));
}

void calprime(int v, int p[]){
    if (!notprime) {
        ++ p[v];
        return ;
    }
    int i = 0;
    while (i < num && v > 1) {
        while (v%prime[i] == 0) {
            ++ p[prime[i]];
            v /= prime[i];
        }
        ++ i;
    }
}

int main(){
    init();
    scanf("%d%d",&n,&m);
    for (int i = 2; i <= n; ++ i) {
        calprime(i, pn);
    }
    for (int i = 2; i <= m; ++ i) {
        calprime(i, pm);
    }
    for (int i = 2; i <= n - m; ++ i) {
        calprime(i, pm);
    }
    int ans = 0;
    for (int i = 2; i <= n; ++ i) {
        if (pn[i] > pm[i]) {
            ++ ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}
