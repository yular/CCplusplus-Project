/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(lgn)
*/
#include <iostream>
#include <cstdio>
using namespace std;

long long ans, u, v;

long long gcd(long long a, long long b){
    return b == 0? a : gcd(b, a%b);
}

int main(){
    for (int i = 0; i < 3; ++ i) {
        scanf("%lld",&v);
        if (i == 0) {
            u = v;
        } else if(i == 1){
            ans = u*v/gcd(u, v);
        } else
            ans = ans*v/gcd(ans, v);
    }
    printf("%lld\n",ans);
    return 0;
}
