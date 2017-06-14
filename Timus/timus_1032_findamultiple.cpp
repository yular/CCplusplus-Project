/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/
#include<iostream>
#include<cstring>
using namespace std;
const int N = 11000;
int n, vis[N], arr[N];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++ i)
	vis[i] = -1;
    bool isfind = false;
    int sum = 0;
    for(int i = 1; i <= n; ++ i){
	scanf("%d",&arr[i]);
	sum = (sum + arr[i])%n;
	if(vis[sum] == -1)
	    vis[sum] = i;
	else{
	    isfind = true;
	    printf("%d\n",i-vis[sum]);
	    for(int j = vis[sum] + 1; j <= i; ++ j)
		printf("%d\n",arr[j]);
	    break;
	}
    }
    if(!isfind)
	puts("0");
    return 0;
}
