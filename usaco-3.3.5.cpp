/*
*
* Tag: DP (Game)
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
const int MOD = 9901;
const int INF = 1<<29;
const double ITF = 1e40;
//const int N = 5100;
const int M = 110;
ifstream fin("game1.in");
ofstream fout("game1.out");
int dp[M][M], sum[M][M], crd[M];
int n;

int main(){
    fin>>n;
    for(int i = 0; i < n; ++ i)
        fin>>crd[i];
    for(int i = 0; i < n; ++ i){
        dp[i][i] = crd[i];
        sum[i][i] = crd[i];
        for(int j = i; j < n; ++ j){
            sum[i][j] = sum[i][j - 1] + crd[j];
        }
    }
    for(int i = 1; i < n; ++ i){
        for(int j = 0; j < n - i; ++ j){
            dp[j][j + i] = sum[j][j + i] - min(dp[j + 1][j + i], dp[j][j + i - 1]);
        }
    }
    fout<<dp[0][n - 1]<<" "<<sum[0][n - 1] - dp[0][n - 1]<<endl;
    return 0;
}
