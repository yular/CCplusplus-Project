/*
*
* Tag: DFS
* Time: O(3^n)
* Space: O(n)
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
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int n, dep;
string exps;

int cal(){
    int res = 0, a = 0;
    int i = 0;
    while(i < exps.size() && exps[i] != '+' && exps[i] != '-'){
        if(exps[i] == ' ')
            a*= 10;
        else
            a += (exps[i] - '0');
        ++ i;
    }
    res = a;
    a = 0;
    while(i < exps.size()){
        char op = exps[i ++];
        while(i < exps.size() && exps[i] != '+' && exps[i] != '-'){
            if(exps[i] == ' ')
                a*= 10;
            else
                a += (exps[i] - '0');
            ++ i;
        }
        if(op == '+')
            res += a;
        else
            res -= a;
        a = 0;
    }
    return res;
}

void dfs(int idx){
    if(idx >= dep){
        if(cal() == 0){
            fout<<exps<<endl;
        }
        return ;
    }
    exps[idx] = ' ';
    dfs(idx + 2);
    exps[idx] = '+';
    dfs(idx + 2);
    exps[idx] = '-';
    dfs(idx + 2);
}

int main(){
    fin>>n;
    dep = n + n - 1;
    exps.resize(dep);
    int dig = 1;
    for(int i = 0; i < exps.size(); ++ i){
        if(i%2 == 0){
            exps[i] = (dig + '0');
            ++ dig;
        }else{
            exps[i] = ' ';
        }
    }
    dfs(1);
    return 0;
}
