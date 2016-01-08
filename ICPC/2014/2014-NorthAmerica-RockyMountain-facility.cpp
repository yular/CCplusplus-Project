/*
*
* Tag: Graph
* Time: O(nm)
* Space: O(nm)
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
const int M = 260;
const int N = 500;
const double eps = 1e-8;
const double dinf = 1e15;
const int MOD = 100000007;
int m, n, k;
bool mp[M][M];
int result[M];
bool visit[M];
int ans;

void init(){
	memset(mp,0,sizeof(mp));
	memset(result,0,sizeof(result));
	memset(visit,0,sizeof(visit));
	ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
            int v;
			scanf("%d",&v);
			if(!v)
                mp[i][j]=true;
		}
	}
}

bool work(){
    init();
    for(int i=1;i<=m; ++ i){
        bool isset = false;
        for(int j=1; j<=n; ++j){
            if(mp[i][j] && !visit[j]){
                visit[j] = 1;
                if(!isset){
                    isset = true;
                    ++ ans;
                }
            }
        }
    }
    for(int i = 1; i <= n; ++ i){
        if(!visit[i]){
            return false;
        }
    }
    return ans < k || ans == k;
}

int main(){
 //   freopen("out.txt","w",stdout);
    while(scanf("%d%d%d",&m,&n,&k) == 3){
        if(work())
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
