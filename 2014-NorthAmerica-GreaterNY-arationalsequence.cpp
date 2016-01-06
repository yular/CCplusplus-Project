/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<climits>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#include<cmath>
#include<list>
#include<sstream>
#include<time.h>
using namespace std;
const int M = 50;
const int N = 100500;
const double eps = 1e-8;
const double dinf = 1e15;
const int MOD = 100000007;
int n, t;

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        int k;
        long long p, q;
        scanf("%d %lld/%lld",&k,&p,&q);
        printf("%d ",k);
        if(!p || !q){
            puts("1/1");
        }else if(p == 1 && q == 1){
            puts("1/2");
        }else if(p == 1){
            printf("%lld/%lld\n",q,q-1);
        }else if(q == 1){
            printf("1/%lld\n",p+1);
        }else{
            if(p < q){
                printf("%lld/%lld\n",q,q-p);
            }else{
                long long n = p/q, r = p%q;
                long long tmpq = q - r;
                long long tmpp = tmpq + r;
                long long p1 = q, q1 = tmpq + n*tmpp;
                printf("%lld/%lld\n",p1,q1);
            }
        }
    }
    return 0;
}
