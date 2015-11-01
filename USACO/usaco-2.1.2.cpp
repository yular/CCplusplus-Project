/*
*
* Tag: Sort
* Time: O(nlogn)
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
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
const int mod = 47;
const int N=30000;
const int M = 1003000;
int n, cnt;
struct fac{
    int u, v;
    double val;
    bool operator < (const fac a)const {
        return a.val < val;
    }
}arr[N];
set<double> st;

int gcd(int a, int b){
    return b==0?a:gcd(b, a%b);
}

int main(){
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    fin>>n;
    fout<<"0/1"<<endl;
    cnt = 0;
    for(int i = 2; i <= n; ++ i){
        for(int j = 1; j < i; ++ j){
            double val = (i*1.0)/(j*1.0);
            if(st.find(val) == st.end()){
                st.insert(val);
                arr[cnt].val = val;
                int gds = gcd(j, i);
                arr[cnt].u = j/gds;
                arr[cnt].v = i/gds;
                ++ cnt;
            }
        }
    }
    sort(arr, arr+cnt);
    for(int i = 0; i < cnt; ++ i){
        fout<<arr[i].u<<"/"<<arr[i].v<<endl;
    }
    fout<<"1/1"<<endl;
    return 0;
}
