/*
*
* Tag: Graph Theory
* Time: 8!
* Space: 8!
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
//const int N = 5100;
const int M = 100;
ifstream fin("msquare.in");
ofstream fout("msquare.out");
map<string, char> path;
map<string, string> pre;
string sta, dest;
queue<string> q;

string opStr(string &u, int op){
    string res(8, '0');
    if(!op){
        for(int i = 0; i < 4; ++ i){
            res[i] = u[7 - i];
            res[7 - i] = u[i];
        }
    }else if(op == 1){
        for(int i = 0; i < 4; ++ i)
            res[i] = u[(3 + i)%4];
        for(int i = 4; i < 8; ++ i)
            res[i] = u[(i + 1)%8];
        res[7] = u[4];
    }else{
        for(int i = 0; i < 8; ++ i)
            res[i] = u[i];
        res[1] = u[6];
        res[2] = u[1];
        res[5] = u[2];
        res[6] = u[5];
    }
    return res;
}

int main(){
    char ch;
    sta.resize(8);
    dest.resize(8);
    for(int i = 0; i < 8; ++ i){
        fin>>ch;
        sta[i] = (i + '1');
        dest[i] = ch;
    }
    path[sta] = 'D';
    pre[sta] = "";
    q.push(sta);
    while(!q.empty()){
        string u = q.front();
        q.pop();
        if(u == dest)
            break;
        string v = opStr(u, 0);
        if(path.find(v) == path.end()){
            path[v] = 'A';
            pre[v] = u;
            q.push(v);
        }
        v = opStr(u, 1);
        if(path.find(v) == path.end()){
            path[v] = 'B';
            pre[v] = u;
            q.push(v);
        }
        v = opStr(u, 2);
        if(path.find(v) == path.end()){
            path[v] = 'C';
            pre[v] = u;
            q.push(v);
        }
    }
    if(path.find(dest) == path.end())
        fout<<"NONE"<<endl;
    else{
        string tmp = dest, ans="";
        while(path[tmp] != 'D'){
            ans += path[tmp];
            tmp = pre[tmp];
        }
        fout<<ans.length()<<endl;
        for(int i = ans.length() - 1; i >= 0; -- i)
            fout<<ans[i];
        fout<<endl;
    }
    return 0;
}
