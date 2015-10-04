/*
*
* Tag: Graph Theory
* Time: c*p*log(p)
* Space: O(p)
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
const int N = 5100;
const int M = 900;
ifstream fin("butter.in");
ofstream fout("butter.out");
struct adjvex
{
	int u,v,w;
	int next;
}edge[N];
int dict[M], head[M];
long long dis[M];
bool vis[M];
long long recd[M][M], mp[M][M];
int n, p, c, num;

void init()
{
	for(int i = 0; i <= p; ++ i)
		head[i]=-1;
	num=0;
}

void add(int a,int b,int c)
{
	edge[num].u=a;
	edge[num].v=b;
	edge[num].w=c;
	edge[num].next=head[a];
	head[a] = num++;
}

struct cmp  {
	bool operator() (const int &a, const int &b)  {
		return dis[a] > dis[b];
    }
};

priority_queue<int, vector<int>, cmp > pq;
void dijk(int sta){
    for(int i = 1; i <= p; ++ i)
        dis[i] = INF;
    dis[sta] = 0;
    while(!pq.empty())
        pq.pop();
    pq.push(sta);
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].v, w = edge[i].w;
            if(dis[v] > dis[u] + w*dict[sta]){
                dis[v] = dis[u] + w*dict[sta];
                pq.push(v);
            }
        }
    }
}

int main(){
    fin>>n>>p>>c;
    init();
    memset(dict, 0, sizeof(dict));
    for(int i = 0; i < n; ++ i){
        int u;
        fin>>u;
        ++ dict[u];
    }

    for(int i = 0; i < c; ++ i){
        int u, v, w;
        fin>>u>>v>>w;
        add(u, v, w);
        add(v, u, w);
    }
    for(int i = 1; i <= p; ++ i){
        if(dict[i]){
            dijk(i);
            for(int j = 1; j <= p; ++ j){
                recd[i][j] = dis[j];
            }
            recd[i][i] = 0;
        }
    }
    long long ans = LLONG_MAX;
    for(int i = 1; i <= p; ++ i){
        long long sum = 0;
        for(int j = 1; j <= p; ++ j){
            sum += recd[j][i];
        }
        ans = min(ans, sum);
    }
    fout<<ans<<endl;
    return 0;
}
