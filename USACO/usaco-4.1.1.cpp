/*
*
* Tag: Math + DP
* Time: O(n*lcm(m1*m2)) where m1 and m2 are the two largest numbers given
* Space: O(1)
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include <ctype.h>
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
const int N = 30;
const int M = 1000100;
int n, m, p;
int arr[N];
bool dp[M];

int gcd(int a, int b){
    return b==0?a:gcd(b, a%b);
}

int main(){
    freopen("nuggets.in","r",stdin);
    freopen("nuggets.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&arr[i]);
    if(n <= 1){
        puts("0");
    }else{
        sort(arr, arr + n);
        int tmp = arr[0];
        for(int i = 1; i < n; ++ i){
            tmp = gcd(tmp, arr[i]);
            if(tmp == 1)
                break;
        }
        if(tmp!=1){
            puts("0");
        }else{
            int sumv = arr[n - 1]*arr[n - 2]/gcd(arr[n - 1], arr[n - 2]);
            dp[0] = 1;
            for(int i = 0; i < n; ++ i){
                for(int j = arr[i]; j <= sumv; ++ j){
                    if(dp[j - arr[i]])
                        dp[j] = 1;
                }
            }
            int ans;
            for(int i = sumv; i > 0; -- i){
                if(!dp[i]){
                    ans = i;
                    break;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
