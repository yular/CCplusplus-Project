/*
*
* Tag: BFS (or DFS)
* Time: O(n^2)
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
const int mod = 47;
const int N=200200;
const int M = 300;
ifstream fin("concom.in");
ofstream fout("concom.out");
int n, bnd;
int stock[M][M], stock1[M][M];
bool vis[M];

int main(){
    fin>>n;
    int a, b, p;
    bnd = 0;
    memset(stock, 0,sizeof(stock));
    memset(stock1, 0,sizeof(stock1));
    memset(vis, 0, sizeof(vis));
    while(n --){
        fin>>a>>b>>p;
        stock[a][b] = p;
        bnd = max(bnd, a);
        bnd = max(bnd, b);
    }
    for(int i = 1; i <= bnd; ++ i){
        queue<int> q;
        set<int> st;
        for(int j = 1; j <= bnd; ++ j){
            if(i == j)
                continue;
            if(stock[i][j] + stock1[i][j]> 50){
                q.push(j);
                st.insert(j);
            }
        }
        while(!q.empty()){
            int j = q.front();
            q.pop();
            for(int k = 1; k <= bnd; ++ k){
                stock1[i][k] += stock[j][k];
                if(stock1[i][k] + stock[i][k] > 50 && st.find(k) == st.end() && i != k){
                    st.insert(k);
                    q.push(k);
                }
            }
        }
    }
    for(int i = 1; i <= bnd; ++ i){
        for(int j = 1; j <= bnd; ++ j){
            if(i == j)
                continue;
            if(stock[i][j] + stock1[i][j] > 50)
                fout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}
