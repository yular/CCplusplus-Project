/*
*
* Tag: Math
* Time: O(n)
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
const int N = 200200;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, k, prm[M], ans;
int prime[N], num;
bool unprime[N];

void calPrime(){
    num = 0;
    for (int i = 2; i < 20000; ++ i) {
        if (! unprime[i]) {
            prime[num ++] = i;
        }
        for (int j = 0; j < num && i*prime[j] < 20000; ++ j ) {
            unprime[i*prime[j]] = 1;
            if (i%prime[j] == 0) {
                break;
            }
        }
    }
}

bool check(int v){
    if ( unprime[v] == false )
        return false;
    for (int i = 0; i < k; ++ i) {
        if (v%prm[i] == 0)
            return false;
    }
    return true;
}


int main(){
    memset(unprime, 0, sizeof(unprime));
    int T;
    scanf("%d",&T);
    calPrime();
    for (int cas = 1; cas <= T; ++ cas) {
        scanf("%d%d",&n,&k);
        ans = 0;
        for (int i = 0; i < k; ++ i) {
            scanf("%d",&prm[i]);
        }
        ans = 0;
        for (int i = 4; i <= n; ++ i) {
            if (check(i)) {
                ++ ans;
            }
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
