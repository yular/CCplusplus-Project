/*
*
* Tag: DP
* Time: O(n*c)
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
const int mod = 47;
const int N=200;
const int M = 250000;
ifstream fin("lamps.in");
ofstream fout("lamps.out");
int n, c;
int oncnt, offcnt;
int on[N], off[N];

void change(string &str, int op){
    if(op == 0){
        for(int i = 0; i < str.size(); ++ i){
            char ch = str[i];
            if(ch == '0')
                str[i] = '1';
            else
                str[i] = '0';
        }
    }else if(op == 1){
        for(int i = 0; i < str.size(); i += 2){
            char ch = str[i];
            if(ch == '0')
                str[i] = '1';
            else
                str[i] = '0';
        }
    }else if(op == 2){
        for(int i = 1; i < str.size(); i += 2){
            char ch = str[i];
            if(ch == '0')
                str[i] = '1';
            else
                str[i] = '0';
        }
    }else{
        for(int i = 0; i < str.size(); i += 3){
            char ch = str[i];
            if(ch == '0')
                str[i] = '1';
            else
                str[i] = '0';
        }
    }
}

int main(){
    fin>>n>>c;
    oncnt = offcnt = 0;
    int dig = 0;
    while(dig!=-1){
        fin>>dig;
        if(dig == -1)
            break;
        -- dig;
        on[oncnt ++] = dig;
    }
    dig = 0;
    while(dig!=-1){
        fin>>dig;
        if(dig == -1)
            break;
        -- dig;
        off[offcnt ++] = dig;
    }
    sort(on, on + oncnt);
    sort(off, off + offcnt);
    string sta(n, '1');
    set<string> dp_prev;
    dp_prev.insert(sta);
    for(int i = 1; i <= c; ++ i){
        set<string> dp_cur;
        set<string>::iterator it = dp_prev.begin();
        for(; it != dp_prev.end(); ++ it){
            string tmp = *it;
            for(int j = 0; j < 4; ++ j){
                string nxt_tmp = tmp;
                change(nxt_tmp, j);
                dp_cur.insert(nxt_tmp);
            }
        }
        dp_prev = dp_cur;
    }
    set<string>::iterator it = dp_prev.begin();
    bool isfind = false;
    for(; it != dp_prev.end(); ++ it){
        string str = *it;
        bool iscorrect = true;
        for(int j = 0; j < oncnt; ++ j){
            if(str[on[j]] != '1'){
                iscorrect = false;
                break;
            }
        }
        if(!iscorrect)
            continue;
        for(int j = 0; j < offcnt; ++ j){
            if(str[off[j]] != '0'){
                iscorrect = false;
                break;
            }
        }
        if(!iscorrect)
            continue;
        fout<<str<<endl;
        isfind = true;
    }
    if(!isfind)
        fout<<"IMPOSSIBLE"<<endl;
    return 0;
}
