/*
*
* Tag: DP
* Time: O(vn)
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
const int N=10200;
const int M = 30;
ifstream fin("money.in");
ofstream fout("money.out");
int n, v;
long long dp[N], coin[M];
int main(){
    fin>>v>>n;
    for(int i = 0; i < v; ++ i)
        fin>>coin[i];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < v; ++ i){
        for(int j = 0; j <= n - coin[i]; ++ j){
            dp[j + coin[i]] += dp[j];
        }
    }
    fout<<dp[n]<<endl;
    return 0;
}
