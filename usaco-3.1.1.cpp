/*
*
* Tag: Graph Theory
* Time: O()
* Space: O(n^2)
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<bitset>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
const int MOD = 9901;
const int INF = 1<<29;
const double ITF = 1e40;
const int N = 10100;
const int M = 110;
ifstream fin("agrinet.in");
ofstream fout("agrinet.out");
int graph[M][M], dist[M];
bool vis[M];
int n, ans;

void prim(){
    ans = 0;
    vis[1] = 1;
    for(int i = 1; i < n; ++ i){
		int minval = INF, k;
		for(int j = 1; j <= n; ++ j){
			if(!vis[j] && dist[j]<minval){
                    minval = dist[j];
                    k = j;
            }
		}
		ans += minval;
		vis[k] = 1;
		for(int j = 1; j <= n; ++ j){
			if(!vis[j] && graph[k][j] < dist[j])
				dist[j] = graph[k][j];
		}
	}
}

int main(){
    fin>>n;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            fin>>graph[i][j];
        }
    }
    for(int i = 1; i <= n; ++ i)
        dist[i] = graph[1][i];
    memset(vis, 0, sizeof(vis));
    prim();
    fout<<ans<<endl;
    return 0;
}
