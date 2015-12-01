/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
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
const int N = 100012;
const int M = 50;
const int LIM = 1000000000;
int n;
string sta, des;
int ans[N], num;

bool dfs(int p){
    ans[num ++] = p;
    if(sta == des)
        return true;
    if(p != 2 && sta[p - 1] == 'B' && sta[p - 2] == 'W'){
        sta[p] = 'W';
        sta[p - 2] = ' ';
        if(dfs(p - 2))
            return true;
        sta[p] = ' ';
        sta[p - 2] = 'W';
    }
    if(p != 1 && sta[p - 1] == 'W'){
        sta[p] = 'W';
        sta[p - 1] = ' ';
        if(dfs(p - 1))
            return true;
        sta[p] = ' ';
        sta[p - 1] = 'W';
    }
    if(p != 2*n + 1 && sta[p + 1] == 'B'){
        sta[p] = 'B';
        sta[p + 1] = ' ';
        if(dfs(p + 1))
            return true;
        sta[p] = ' ';
        sta[p + 1] = 'B';
    }
    if(p != 2*n && sta[p + 1] == 'W' && sta[p + 2] == 'B'){
        sta[p] = 'B';
        sta[p + 2] = ' ';
        if(dfs(p + 2))
            return true;
        sta[p] = ' ';
        sta[p + 2] = 'B';
    }
    -- num;
    return false;
}

int main(){
    freopen("shuttle.in","r",stdin);
    freopen("shuttle.out","w",stdout);
    cin>>n;
    sta = " ";
    des = " ";
    num = 0;
    for(int i = 1; i <= 2*n + 1; ++ i){
        if(i == n + 1){
            sta += ' ';
            des += ' ';
        }else if(i <= n){
            sta += 'W';
            des += 'B';
        }else{
            sta += 'B';
            des += 'W';
        }
    }
    num = 0;
    dfs(n + 1);
    cout<<ans[1];
    for(int i = 2; i < num; ++ i){
        if(i%20 == 1)
            cout<<endl<<ans[i];
        else
            cout<<" "<<ans[i];
    }
    cout<<endl;
    return 0;
}
