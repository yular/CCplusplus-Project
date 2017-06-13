/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/
#include<iostream>
using namespace std;
const int N = 100100;
int n;
long long arr[N];

long long llabs(long long v){
    return v < 0? -v : v;
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i)
	scanf("%lld",&arr[i]);
    int ans = 0;
    for(int i = 1; i < n; ++ i){
	if(llabs(arr[i] - arr[i - 1]) > llabs(arr[ans] - arr[ans - 1]))
	    ans = i;
    }
    printf("%d %d\n",ans,ans + 1);
    return 0;
}
