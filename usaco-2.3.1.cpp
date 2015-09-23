/*
*
* Tag: DP
* Time: O(mn) //m is the length of sequence of constituents, and n is the number of primitives
* Space: O(mn)
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
ifstream fin("prefix.in");
ofstream fout("prefix.out");
int n, v;
string prim[M];
bool dp[N];
int cnt_prim;
string str_const;
int main(){
    cnt_prim = 0;
    string inpt;
    while(fin>>inpt){
        if(inpt == ".")
            break;
        prim[cnt_prim ++] = inpt;
    }
    while(fin>>inpt){
        str_const += inpt;
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    int ans = 0, len = str_const.size();
    for(int i = -1; i < len - 1; ++ i){
        if(i >= 0 && !dp[i])
            continue;
        for(int j = 0; j < cnt_prim; ++ j){
            int str_len = prim[j].size();
            if(i + str_len >= len || prim[j] != str_const.substr(i + 1, str_len))
                continue;
            dp[i + str_len] = 1;
        }
    }
    bool isfind = false;
    for(int i = len - 1; i >= 0; -- i){
        if(dp[i]){
            fout<<i + 1<<endl;
            isfind = true;
            break;
        }
    }
    if(!isfind)
        fout<<"0"<<endl;
    return 0;
}
