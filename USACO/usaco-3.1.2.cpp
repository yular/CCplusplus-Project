/*
*
* Tag: DP
* Time: O(nm)
* Space: O(m)
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
const int N = 10100;
const int M = 210;
ifstream fin("inflate.in");
ofstream fout("inflate.out");
int n, m;
int v[N], w[N];
int dp[N];

int main(){
    fin>>m>>n;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++ i){
        fin>>v[i]>>w[i];
    }
    dp[0] = 0;
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j <= m - w[i]; ++ j){
            dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
        }
    }
    fout<<dp[m]<<endl;
    return 0;
}
