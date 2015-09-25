/*
*
* Tag: Graph Theory
* Time: O(n^3)
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
const int N = 210;
const int M = 110;
ifstream fin("comehome.in");
ofstream fout("comehome.out");
int p, w;
int mp[M][M];
string a, b;

void init(){
    for(int i = 0; i < M; ++ i){
        for(int j = 0; j < M; ++ j){
            if(i == j)
                mp[i][j] = 0;
            else
                mp[i][j] = INF;
        }
    }
}

void floyd(){
    for(int k = 0; k < 52; ++ k){
        for(int i = 0; i < 52; ++ i){
            for(int j = 0; j < 52; ++ j){
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
}

int main(){
    init();
    fin>>p;
    while(p --){
        fin>>a>>b>>w;
        int u, v;
        if(a[0] >= 'A' && a[0] <= 'Z'){
            u = a[0] - 'A';
        }else{
            u = a[0] - 'a' + 26;
        }
        if(b[0] >= 'A' && b[0] <= 'Z'){
            v = b[0] - 'A';
        }else{
            v = b[0] - 'a' + 26;
        }
        mp[u][v] = min(mp[u][v], w);
        mp[v][u] = min(mp[v][u], w);
    }
    floyd();
    char ans_p;
    int ans_dis = INF;
    for(int i = 0; i < 25; ++ i){
        if(ans_dis > mp[i][25]){
            ans_dis = mp[i][25];
            ans_p = ('A' + i);
        }
    }
    fout<<ans_p<<" "<<ans_dis<<endl;
    return 0;
}
