/*
*
* Tag: DP
* Time: O(mnk) where m is the largest number in array
* Space: O(mnk)
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
const int N = 2002000;
const int M = 210;
ifstream fin("stamps.in");
ofstream fout("stamps.out");
int arr[M];
int k, n;
int dp[N];

int main(){
    fin>>k>>n;
    for(int i = 0; i < n; ++ i){
        fin>>arr[i];
    }
    sort(arr, arr+n);
    int ans = 0;
    dp[ans] = 0;
    while(dp[ans] <= k){
        ++ ans;
        int tmp = INT_MAX;
        for(int i = 0; i < n; ++ i){
            if(ans >= arr[i]){
                tmp = min(tmp, dp[ans - arr[i]] + 1);
            }else
                break;
        }
        dp[ans] = tmp;
    }
    -- ans;
    fout<<ans<<endl;
    return 0;
}
