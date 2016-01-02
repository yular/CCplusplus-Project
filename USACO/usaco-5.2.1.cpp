/*
*
* Tag: DFS
* Time: ?
* Space: O(n^2)
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
//#include<queue>
#include<set>
#include<bitset>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
const int MOD = 9901;
const int INF = 1<<29;
const double ITF = 1e40;
const int N = 10010;
const int M = 200;
const int LIM = 1000000000;
const double eps=1e-8;
char mp[M][M];
int ans;
int n, b, c;

void dfs(int x, int y, int step){
    int dx, dy;
    bool flag;

    for(dx = x + 1, dy = y, flag = false; dx <= n; ++ dx){
        if(mp[dx][dy] == '#')
            break;
        if(mp[dx][dy] == 1){
            ans = max(ans, step + dx - x);
            flag = true;
            break;
        }
        mp[dx][dy] = 1;
    }
    -- dx;
    if(!flag && !(dx == x && dy == y))
        dfs(dx, dy, step + dx - x);
    for ( ; dx >= x + 1; -- dx)
        mp[dx][dy]=0;

    for(dx = x - 1, dy = y, flag = false; dx >= 1; -- dx){
        if(mp[dx][dy] == '#')
            break;
        if(mp[dx][dy] == 1){
            ans = max(ans, step + x - dx);
            flag = true;
            break;
        }
        mp[dx][dy] = 1;
    }
    ++ dx;
    if(!flag && !(dx == x && dy == y))
        dfs(dx, dy, step + x - dx);
    for ( ; dx <= x - 1; ++ dx)
        mp[dx][dy]=0;

    for(dx = x, dy = y + 1, flag = false; dy <= n; ++ dy){
        if(mp[dx][dy] == '#')
            break;
        if(mp[dx][dy] == 1){
            ans = max(ans, step + dy - y);
            flag = true;
            break;
        }
        mp[dx][dy] = 1;
    }
    -- dy;
    if(!flag && !(dx == x && dy == y))
        dfs(dx, dy, step + dy - y);
    for ( ; dy >= y + 1; -- dy)
        mp[dx][dy]=0;

    for(dx = x, dy = y - 1, flag = false; dy >= 1; -- dy){
        if(mp[dx][dy] == '#')
            break;
        if(mp[dx][dy] == 1){
            ans = max(ans, step + y - dy);
            flag = true;
            break;
        }
        mp[dx][dy] = 1;
    }
    ++ dy;
    if(!flag && !(dx == x && dy == y))
        dfs(dx, dy, step + y - dy);
    for ( ; dy <= y - 1; ++ dy)
        mp[dx][dy]=0;
}

int main(){
    freopen("snail.in","r",stdin);
    freopen("snail.out","w",stdout);
    scanf("%d%d",&n,&b);
    char a;
 //   printf("%d %d\n",n,b);
    for(int i = 1; i <= b; ++ i){
        getchar();
        scanf("%c%d",&a,&c);
        a =(a - 'A') + 1;
        mp[a][c] = '#';
    }
    ans = 0;
    mp[1][1] = 1;
    dfs(1, 1, 0);
    printf("%d\n",ans);
    return 0;
}
