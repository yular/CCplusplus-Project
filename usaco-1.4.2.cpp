/*
ID: ybccome1
PROG: milk3
LANG: C++
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<climits>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
const int N=22;
struct btl{
    int a,b,c;
};
bool visall[N][N][N];

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("milk3.in");
    fout.open("milk3.out");
    int a,b,c;
    fin>>a>>b>>c;
    btl sta;
    sta.a = 0;
    sta.b = 0;
    sta.c = c;
    fin.close();
    queue<btl> q;
    vector<bool> vis;
    vis.resize(c +3);
    vis[c] = 1;
    vector<int> ans;
    ans.push_back(c);
    q.push(sta);
    visall[0][0][c] = 1;

    while(!q.empty()){
        btl cur = q.front(), nxt;
        q.pop();
        int ta,tb,tc, na, nb, nc;
        ta = cur.a;
        tb = cur.b;
        tc = cur.c;
        if(tc > 0){
            if(ta < a){
                if(a - ta >= tc){
                    na = ta + tc;
                    nb = tb;
                    nc = 0;
                }else{
                    na = a;
                    nb = tb;
                    nc = tc - (a - ta);
                }
                if(!visall[na][nb][nc]){
                    visall[na][nb][nc] = 1;
                    nxt.a = na;
                    nxt.b = nb;
                    nxt.c = nc;
                    q.push(nxt);
                    if(!vis[nc] && na == 0){
                        vis[nc] = 1;
                        ans.push_back(nc);
                    }
                }
            }
            if(tb < b){
                if(b - tb >= tc){
                    na = ta;
                    nb = tb + tc;
                    nc = 0;
                }else{
                    na = ta;
                    nb = b;
                    nc = tc - (b - tb);
                }
                if(!visall[na][nb][nc]){
                    visall[na][nb][nc] = 1;
                    nxt.a = na;
                    nxt.b = nb;
                    nxt.c = nc;
                    q.push(nxt);
                    if(!vis[nc] && na == 0){
                        vis[nc] = 1;
                        ans.push_back(nc);
                    }
                }
            }
        }

        if(tb > 0){
            if(ta < a){
                if(a - ta >= tb){
                    na = ta + tb;
                    nb = 0;
                    nc = tc;
                }else{
                    na = a;
                    nb = tb - (a - ta);
                    nc = tc;
                }
                if(!visall[na][nb][nc]){
                    visall[na][nb][nc] = 1;
                    nxt.a = na;
                    nxt.b = nb;
                    nxt.c = nc;
                    q.push(nxt);
                    if(!vis[nc] && na == 0){
                        vis[nc] = 1;
                        ans.push_back(nc);
                    }
                }
            }
            if(tc < c){
                if(c - tc >= tb){
                    na = ta;
                    nb = 0;
                    nc = tc + tb;
                }else{
                    na = ta;
                    nb = tb - (c - tc);
                    nc = c;
                }
                if(!visall[na][nb][nc]){
                    visall[na][nb][nc] = 1;
                    nxt.a = na;
                    nxt.b = nb;
                    nxt.c = nc;
                    q.push(nxt);
                    if(!vis[nc] && na == 0){
                        vis[nc] = 1;
                        ans.push_back(nc);
                    }
                }
            }
        }

        if(ta > 0){
            if(tb < b){
                if(b - tb >= ta){
                    na = 0;
                    nb = tb + ta;
                    nc = tc;
                }else{
                    na = ta - (b - tb);
                    nb = b;
                    nc = tc;
                }
                if(!visall[na][nb][nc]){
                    visall[na][nb][nc] = 1;
                    nxt.a = na;
                    nxt.b = nb;
                    nxt.c = nc;
                    q.push(nxt);
                    if(!vis[nc] && na == 0){
                        vis[nc] = 1;
                        ans.push_back(nc);
                    }
                }
            }
            if(tc < c){
                if(c - tc >= ta){
                    na = 0;
                    nb = tb;
                    nc = tc + ta;
                }else{
                    na = ta - (c - tc);
                    nb = tb;
                    nc = c;
                }
                if(!visall[na][nb][nc]){
                    visall[na][nb][nc] = 1;
                    nxt.a = na;
                    nxt.b = nb;
                    nxt.c = nc;
                    q.push(nxt);
                    if(!vis[nc] && na == 0){
                        vis[nc] = 1;
                        ans.push_back(nc);
                    }
                }
            }
        }

    }
    sort(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i ++){
        if(i)
            fout<<" ";
        fout<<ans[i];
    }
    fout<<endl;
    fout.close();
    return 0;
}
