/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
#include<iostream>
using namespace std;
long long n, v, sum;
int m, cnt;

int main(){
    scanf("%lld%d",&n,&m);
    n*=3;
    cnt = 1;
    sum = 0;
    for(int i = 0; i < m; ++ i){
	scanf("%lld",&v);
	sum += v;
	if(sum > n)
	    break;
	++ cnt;
    }
    if(sum <= n)
	puts("Team.GOV!");
    else
	printf("Free after %d times.\n",cnt);
    return 0;
}
