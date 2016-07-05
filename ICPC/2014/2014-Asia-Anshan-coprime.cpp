/*
 *
 * Tag: Math
 * Time: ?
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 113;
const int M = 210000;
const long long MOD = 1000000007;
const double eps = 1e-10;
int a[M], prime[M],num[M], fact[N][2];
int tot, cntf;
long long n;

void getprime(){
    tot = 0;
    memset(prime, 0,sizeof(prime));
    for (int i = 2; i < M; ++ i) {
        if(!prime[i])
            prime[tot ++] = i;
        for(int j = 0; j < tot && prime[j] <= M/i; ++ j){
            prime[prime[j]*i] = 1;
            if (i%prime[j] == 0)
                break;
        }
    }
 //   printf("%d\n",tot);
}

int getfact(int x){
    cntf=0;
    for(int i=0;prime[i]<=x/prime[i];i++){
        if(x%prime[i] == 0){
            fact[cntf][0]=prime[i];
            fact[cntf][1]=0;
            while(x%prime[i] == 0){
                fact[cntf][1]++;
                x/=prime[i];
            }
            cntf++;
        }
    }
    if(x!=1){
        fact[cntf][0]=x; fact[cntf++][1]=1;
    }
    return cntf;
}

int main(){
    int T;
    getprime();
    scanf("%d",&T);
    while (T --) {
        scanf("%lld",&n);
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&a[i]);
            getfact(a[i]);
            for (int st = 1; st < (1<<cntf); ++ st) {
                int res = 1;
                for (int k = 0; k < cntf; ++ k) {
                    if (st&(1<<k)) {
                        res *= fact[k][0];
                    }
                }
                ++ num[res];
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < n; ++ i) {
            getfact(a[i]);
            long long cnt1 = 0;
            for (int st = 1; st < (1<<cntf); ++ st) {
                int res = 1, cnt2 = 0;
                for (int k = 0; k < cntf; ++ k) {
                    if (st & (1<<k)) {
                        ++ cnt2, res*=fact[k][0];
                    }
                }
                if (cnt2&1) {
                    cnt1 += num[res];
                } else {
                    cnt1 -= num[res];
                }
            }
            if (a[i] == 1) {
                ++ cnt1;
            }
            ans += (cnt1 - 1)*(n - cnt1);
        }
        ans = n*(n - 1)*(n - 2)/6 - ans/2;
        printf("%lld\n", ans);
    }
    return 0;
}
