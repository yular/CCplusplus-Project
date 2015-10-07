/*
*
* Tag: Brute Force
* Time: O(1)
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
const int N = 5100;
const int M = 100;
ifstream fin("spin.in");
ofstream fout("spin.out");
struct wheel {
    int speed;
    int qcnt;
    int q_e[5], q_s[5];
}w[5];

bool check(){
    bool flag;
    int p;
    for(int i = 0; i < 360; ++ i){
        p = 0;
        for(int a = 0; a < 5; ++ a){
            flag = false;
            for(int b = 0; b < w[a].qcnt; ++ b){
                if((i>=w[a].q_s[b] && i<=w[a].q_e[b] && w[a].q_s[b]<=w[a].q_e[b]) ||( (i<=w[a].q_e[b] || i>=w[a].q_s[b]) && w[a].q_s[b]>w[a].q_e[b])){
                    flag = true;
                    break;
                }
            }
            if(flag)
                ++ p;
        }
        if(p == 5)
            return true;
    }
    return false;
}

void print(int k){
    if(k == -1)
        fout<<"none"<<endl;
    else
        fout<<k<<endl;
}


int main(){
    int l;
    for(int i = 0; i < 5; ++ i){
        fin>>w[i].speed>>w[i].qcnt;
        for(int j = 0; j < w[i].qcnt; ++ j){
            fin>>w[i].q_s[j]>>l;
            w[i].q_e[j] = w[i].q_s[j]+l;
            if(w[i].q_e[j] >= 360)
                w[i].q_e[j] -= 360;
        }
    }

    bool isfind = false;
    for(int t = 0; t < 360; ++ t){
        if(check()){
            isfind = true;
            print(t);
            break;
        }
        for(int i = 0; i < 5; ++ i){
            for(int j = 0; j < w[i].qcnt; ++ j){
                w[i].q_s[j] += w[i].speed;
                if(w[i].q_s[j] >= 360)
                    w[i].q_s[j] -= 360;
                 w[i].q_e[j] += w[i].speed;
                 if(w[i].q_e[j] >= 360)
                    w[i].q_e[j] -= 360;
            }
        }
    }
    if(!isfind)
        print(-1);
    return 0;
}
