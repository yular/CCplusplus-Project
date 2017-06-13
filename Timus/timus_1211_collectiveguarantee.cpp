/*
*
* Tag: Search
* Time: O(n)
* Space: O(n)
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 25100;
int arr[N], n, vis[N], idx;

bool hasloop(int s){
    while(s && (!vis[s])) {
	vis[s] = idx;
	s = arr[s];
    }
    return (s && vis[s] == idx);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
	int cnt = 0;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++ i){
	    scanf("%d",&arr[i]);
	    if(arr[i] == 0)
		++ cnt;
	}
	if(cnt != 1){
	    puts("NO");
	    continue;	
	}
	memset(vis, 0, sizeof(vis));
	idx = 0;
	bool canfind = true;
	for(int i = 1; i <= n; ++ i){
	    if(!vis[i]){
		++ idx;
		if(hasloop(i)){
		    canfind = false;
		    break;
		}
	    }
	}
	if(canfind)
	    puts("YES");
	else
	    puts("NO");
    }
    return 0;
}
