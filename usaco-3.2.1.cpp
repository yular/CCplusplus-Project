/*
*
* Tag: Math
* Time: O(n)
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
const int MOD = 9901;
const int INF = 1<<29;
const double ITF = 1e40;
const int N = 10100;
const int M = 1000;
ifstream fin("fact4.in");
ofstream fout("fact4.out");
int n;

int main(){
    fin>>n;
    int ans = 1;
    for(int i = 2; i <= n; ++ i){
        ans *= i;
        while(ans%10 == 0)
            ans /= 10;
        ans %= M;
    }
    fout<<ans%10<<endl;
    return 0;
}
