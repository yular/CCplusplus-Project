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
const int MOD = 9901;
const int INF = 1<<29;
const double ITF = 1e40;
//const int N = 5100;
const int M = 310;
ifstream fin("range.in");
ofstream fout("range.out");
struct squart{
    int sz, cnt;
    bool operator < (const squart a) const {
        return a.cnt < cnt;
    }
}vec[M];
int dp[M][M], ans[M];
int n;

int main(){
    fin>>n;
    for(int i = 0; i < n; ++ i){
        string line;
        fin>>line;
        for(int j = 0; j < n; ++ j){
            dp[i][j] = line[j] - '0';
        }
    }
    for(int i = 0; i < n; ++ i){
        for(int j = 1; j < n; ++ j){
            if(dp[i][j] == 0)
                continue;
            dp[i][j] += dp[i][j - 1];
        }
    }
    for(int i = 1; i < n; ++ i){
        for(int j = 1; j < n; ++ j){
            if(dp[i][j] >= 2){
                int cnt = 1, idx = dp[i][j];
                for(int k = i - 1; k >= 0; -- k){
                    idx = min(idx, dp[k][j]);
                    ++ cnt;
                    if(cnt > idx)
                        break;
                    ++ ans[min(idx, cnt)];
                }
            }
        }
    }
    int num = 0;
    for(int i = 2; i <= n; ++ i){
        if(ans[i]){
            vec[num].sz = i;
            vec[num ++].cnt = ans[i];
        }
    }
    sort(vec, vec + num);
    for(int i = 0; i < num; ++ i){
        fout<<vec[i].sz<<" "<<vec[i].cnt<<endl;
    }
    return 0;
}

