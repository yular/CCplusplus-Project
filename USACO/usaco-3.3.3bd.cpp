/*
*
* Tag: Graph Theory
* Time:
* Space: O(n^4)
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include <ctype.h>
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
const int N = 10;
const int M = 1010;
//ifstream fin("camelot.in");
//ofstream fout("camelot.out");
struct position_T
{
    int x,y;
}king,knight[26 * 30 + 10];
struct Qnode
{
    int x,y;
};
int cnt = 0;
int r,c;
int jx[8] = {1,1,-1,-1,2,2,-2,-2};
int jy[8] = {2,-2,2,-2,1,-1,1,-1};
int mx[8] = {0,0,1,1,1,-1,-1,-1};
int my[8] = {1,-1,0,-1,1,0,1,-1};
long jdist[31][31][31][31];
long king_dist[31][31];
Qnode queues[26 * 30 + 10];
int head,tail;

void init(){
    char tx, tt;
    cin>>r>>c;
    getchar();
    cin>>tx>>king.y;
    getchar();
    king.y -= 1;
    king.x = tx - 'A';
    cnt = 0;
    while(!feof(stdin)){
        cin>>tx;
        if(isalpha(tx)){
            cin>>knight[cnt].y;
            knight[cnt].y --;
            knight[cnt].x = tx - 'A';
            cnt ++;
        }
    }
}

void enqueue(int x,int y)
{
    queues[tail].x = x;
    queues[tail].y = y;
    tail ++;
}

Qnode dequeue()
{
    return queues[head ++];
}

void jbfs(int sx,int sy)  //计算jdist数组
{
    int i,j,k,x,y;
    head = tail = 0;
    for(i = 0;i < c;i ++)
        for(j = 0;j < r;j ++)
            jdist[sx][sy][i][j] = INF;
    jdist[sx][sy][sx][sy] = 0;
    enqueue(sx,sy);
    Qnode now;
    while(head < tail)
    {
        now = dequeue();
        for(k = 0;k < 8;k ++)
        {
            x = now.x + jx[k];
            y = now.y + jy[k];
            if((x >= 0) && (x < c) && (y >= 0) && (y < r) && jdist[sx][sy][x][y] == INF)
            {
                jdist[sx][sy][x][y] = jdist[sx][sy][now.x][now.y] + 1;
                enqueue(x,y);
            }
        }
    }
}


void king_bfs()    //计算king_dist数组
{
    int i,j,k,x,y;
    head = tail = 0;
    x = king.x;
    y = king.y;
    for(i = 0;i < c;i ++)
        for(j = 0;j < r;j ++)
            king_dist[i][j] = INF;
    king_dist[x][y] = 0;
    enqueue(x,y);
    Qnode now;
    while(head < tail)
    {
        now = dequeue();
        for(k = 0;k < 8;k ++)
        {
            x = now.x + mx[k];
            y = now.y + my[k];
            if((x >= 0) && (x < c) && (y >= 0) && (y < r) && king_dist[x][y] == INF)
            {
                king_dist[x][y] = king_dist[now.x][now.y] + 1;
                enqueue(x,y);
            }
        }
    }
}

long solve(int x,int y)   //计算所有在(x,y)点汇集的最小步数
{
    int i,j,k;
    long res = INF;
    long dist_part = 0;  //所有骑士跳跃到该店的最小步数和
    long pick_dist = INF;  //某个骑士去“接”国王相对于直接到达（x，y）点多走的步数
    for(i = 0;i < cnt;i ++)
    {
        //printf("%d:%ld\n",i,jdist[knight[i].x][knight[i].y][x][y]);
        dist_part += jdist[knight[i].x][knight[i].y][x][y];
        if(jdist[knight[i].x][knight[i].y][x][y] == INF)    return INF;
    }
    for(i = 0;i < c;i ++)
        for(j = 0;j < r;j ++)
        {
            if(king_dist[i][j] > 4)    continue;  //国王走太远就不考虑了
            for(k = 0;k < cnt;k ++)   //对每个骑士进行枚举，算出pick_dist的最小值
            {
                if(king_dist[i][j] + jdist[knight[k].x][knight[k].y][i][j] + jdist[i][j][x][y] - jdist[knight[k].x][knight[k].y][x][y] >= 0)
                    pick_dist = min(pick_dist,king_dist[i][j] + jdist[knight[k].x][knight[k].y][i][j] + jdist[i][j][x][y] - jdist[knight[k].x][knight[k].y][x][y]);
            }
        }
    res = min(dist_part + king_dist[x][y],dist_part + pick_dist);
    return res;
}

int main(){
    freopen("camelot.in","r",stdin);
    freopen("camelot.out","w",stdout);
    init();
    for(int i = 0; i < c; ++ i){
        for(int j = 0; j < r; ++ j){
            jbfs(i, j);
        }
    }
    king_bfs();
    long ans = INF;
    for(int i = 0;i < c; ++ i){
        for(int j = 0;j < r; ++ j){
            ans = min(ans,solve(i,j));
        }
    }
    cout<<ans<<endl;
    return 0;
}
