/*
*
* Tag: Brute Force
* Time: ?
* Space: O(1)
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
const int N=200;
const int M = 250000;
ifstream fin("runround.in");
ofstream fout("runround.out");
long long n;

int rnd(int sta, int stp, int bnd){
    while(!(sta + stp <= bnd))
        stp -= bnd;
    return sta + stp;
}

bool check(long long cur){
    char s[11];
    int m;
    bool vis[11];
    sprintf(s+1,"%ld",n);
    m=strlen(s+1);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= m; ++ i){
        if(!vis[s[i] - '0'])
            vis[s[i] - '0'] = 1;
        else
            return false;
    }
    memset(vis, 0, sizeof(vis));
    int i = 1, j;
    for(int k = 1; k < m; ++ k){
        vis[i] = 1;
        j = rnd(i, s[i] - '0', m);
        if(vis[j])
            return false;
        i = j;
    }
    j = rnd(i, s[i] - '0', m);
    if(s[j] == s[1])
        return true;
    return false;
}

int main(){
    fin>>n;
    ++ n;
    while(!check(n))
        ++ n;
    fout<<n<<endl;
    return 0;
}
