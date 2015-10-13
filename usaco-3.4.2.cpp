/*
*
* Tag: Math (Pick Theorem)
* Time: O(lgn)
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
const int M = 1010;
int n, m, p;

int gcd(int a, int b){
    return b==0?a:gcd(b, a%b);
}

int main(){
    freopen("fence9.in","r",stdin);
    freopen("fence9.out","w",stdout);
    cin>>n>>m>>p;
    double s = p*m/2.0;
    int w1, w2, b;
    w1 = gcd(n, m);
    w2 = gcd(m, abs(p - n));
    b = p + w1 + w2;
    int ans = s - b/2.0 + 1;
    cout<<ans<<endl;
    return 0;
}
