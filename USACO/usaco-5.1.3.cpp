/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
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
//#include<queue>
#include<set>
#include<bitset>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
const int MOD = 9901;
const int INF = 1<<29;
const double ITF = 1e40;
const int N = 10010;
const int M = 200;
const int LIM = 1000000000;
const double eps=1e-8;
int arr[N];
int n, ans;

int main(){
    freopen("theme.in","r",stdin);
    freopen("theme.out","w",stdout);
    int u;
    scanf("%d%d",&n,&u);
    for(int i = 1; i < n; ++ i){
        int v;
        scanf("%d",&v);
        arr[i] = v - u;
        u = v;
    }
    arr[n] = INT_MAX;
    int len = 1, k;
    for(int i = 1; i <= n - ans; ++ i){
        for(int j = i + ans; j <= n - ans; ++ j){
            if(arr[i] == arr[j]){
                len = 1;
                k = j;
                while(arr[i + len] == arr[j + len] && k>i+len+1) ++ len;
                ans = max(ans, len);
            }
        }
    }
    if(ans < 4)
        ans = -1;
    printf("%d\n",ans+1);
    return 0;
}
