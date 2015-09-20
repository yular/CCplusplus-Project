/*
*
* Tag: DP
* Time: O(n^3)
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
const int N=1500;
const int M = 250000;
ifstream fin("subset.in");
ofstream fout("subset.out");
long long dp[N];
int n;

int main(){
    fin>>n;
    int sum = n*(n + 1)/2;
    if(sum%2){
        fout<<"0"<<endl;
    }else{
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int id = sum/2, bnd = 1;
        for(int i = 1; i <= n; ++ i){
            for(int j = id; j >= i; -- j){
                dp[j] += dp[j - i];
            }
        }
        fout<<dp[id]/2<<endl;
    }
    return 0;
}
