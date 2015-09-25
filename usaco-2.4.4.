/*
*
* Tag: Math
* Time: O(m)
* Space: ?
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
const int N = 100200;
const int M = 110;
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
int n, m, cnt;
string ans;
bool vis[N];
map<int, int> dict;

int main(){
    fin>>n>>m;
    cnt = 0;
    if(n%m == 0){
        fout<<n/m<<".0"<<endl;
    }else{
        ans.resize(N);
        int u = n/m, v, w;
        string tmp = "";
        w = n - u*m;
        if(!u)
            ans[cnt ++] = '0';
        else{
            while(u){
                v = u%10;
                tmp += (v + '0');
                u /= 10;
            }
            for(int i = tmp.size() - 1; i >= 0; -- i){
                ans[cnt ++] = tmp[i];
            }
        }
        ans[cnt ++] = '.';
        int tot = 0, start = 0;
        bool isrep = false;
        while(tot < m){
            w = w*10;
            if(w%m == 0){
                ans[cnt ++] = (w/m + '0');
                break;
            }else{
                if(dict.find(w) == dict.end()){
            //        cout<<w<<endl;
                    ans[cnt ++] = (w/m + '0');
                    dict[w] = w/m;
                    ++ tot;
                    w = w%m;
                }else{
                    v = dict[w];
                    isrep = true;
                    ans[cnt ++] = ')';
                  //  cout<<" -- "<<endl;
                    break;
                }
            }
        }
        bool isfirst = true, beforedot = true;
        int id = 0;
        for(int i = 0; i < cnt; ++ i){
            if(id%76 == 0 && isfirst == false)
                fout<<endl;
            if(ans[i] == '.'){
                fout<<ans[i];
                beforedot = false;
            }else{
                if(beforedot)
                    fout<<ans[i];
                else{
                    if(isrep){
                        if(ans[i] - '0' == v){
                            fout<<'(';
                            -- i;
                            v = -1;
                        }else{
                            fout<<ans[i];
                        }
                    }else{
                        fout<<ans[i];
                    }
                }
            }
            ++ id;
            isfirst = false;
        }
        fout<<endl;
    }
    return 0;
}
