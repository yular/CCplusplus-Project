/*
*
* Tag: Set (Data Structure)
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
#include<bitset>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
const int MOD = 9901;
const int INF = 2000000020;
const double ITF = 1e40;
const int N = 10100;
const int M = 110;
ifstream fin("humble.in");
ofstream fout("humble.out");
int n, k, cnt;
//priority_queue<int, vector<int>, greater<int> > pq;
set<int> st;
int hum_num[M];
int res;

void init(){
    st.insert(1);
    cnt = -1;
    while(st.size()){
        int u = *(st.begin());
        st.erase(u);
    //    printf(" u = %d\n",u);
        ++ cnt;
        if(cnt == n){
            res = u;
            break;
        }
        for(int i = 0; i < k; ++ i){
            long long v = (long long)u*(long long)hum_num[i];
            if(v >= 2 && v <= (long long)INT_MAX && st.find(v) == st.end()){
                if(st.size() > n){
                    int w = *(-- st.end());
                    st.erase(w);
                    if(v > *(-- st.end()))
                        break;
                }
                st.insert((int)v);
            }
        }
    }
}

int main(){
    fin>>k>>n;
    for(int i = 0; i < k; ++ i)
        fin>>hum_num[i];
    init();
    fout<<res<<endl;
    return 0;
}
