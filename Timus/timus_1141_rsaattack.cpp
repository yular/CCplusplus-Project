/*
*
* Tag: Number Theory
* Time: O(lgn)
* Space: O(1)
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, e, c, p, q, x, y;

bool isprime(int v){
    for(int i = 2; i*i <= v; ++ i){
	if(v%i == 0)
	    return false;
    }
    return true;
}

void calc(int a, int b, int &x, int &y) {
    int t;
    if(b == 0) {
	x = 1, y = 0;
	return ;
    }
    calc(b, a%b, x, y);
    t = x, x = y;
    y = t - (a/b)*y;
}

int powmod(int a, int n, int m){
    int tmp = a, res = 1;

    while(n > 0) {
	if(n&1) {
	    res *= tmp;
	    res %= m;
	}
	tmp *= tmp;
	tmp %= m;
	n >>= 1;
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
	scanf("%d%d%d",&e,&n,&c);
	x = y = 0;
	for(int i = 2; i*i <= n; ++ i){
	    if(n%i == 0 && isprime(i) && isprime(n/i)){
		p = i, q = n/i;
		break;
	    }
	}
	calc(e, (p-1)*(q-1), x, y);
	if(x < 0)
	    x = (x + (p - 1)*(q - 1))%((p - 1)*(q - 1));
	int ans = powmod(c, x, n);
	printf("%d\n",ans);
    }
    return 0;
}
