/*
*
* Tag: DFS
* Time: O(n*(2^b))
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
const int N=1000;
const int M = 1003000;
int n, b, d;
int ans[N], bnd, cnt;
bool isfind;

bool check(int val){
    for(int i = 0; i < cnt; ++ i){
        int tmp = val^ans[i];
        int bcnt = 0;
        while(tmp){
            if(tmp&1)
                ++ bcnt;
            tmp>>=1;
        }
        if(bcnt < d)
            return false;
    }
    return true;
}

void search_ans(int dep){
    if(dep >= n){
        isfind = true;
        return ;
    }
    for(int i = ans[dep - 1] + 1; i < bnd; ++ i){
        if(check(i)){
            ans[dep] = i;
            ++ cnt;
            search_ans(dep + 1);
            if(isfind)
                return ;
        }
    }
}

int main(){
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");
    fin>>n>>b>>d;
    cnt = 0;
    bnd = 1<<b;
    isfind = false;
    for(int i = 0; i < bnd; ++ i){
        ans[0] = i;
        ++ cnt;
        search_ans(1);
        if(isfind)
            break;
    }
    for(int i = 0; i < n - 1; ++ i){
        fout<<ans[i];
        if((i + 1)%10 == 0)
            fout<<endl;
        else
            fout<<" ";
    }
    fout<<ans[n - 1]<<endl;
    return 0;
}
