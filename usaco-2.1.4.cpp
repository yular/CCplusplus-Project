/*
*
* Tag: DFS, Pruning
* Time: O(2^n)
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
const int N=1000;
const int M = 1003000;
struct holst{
    vector<int> scop;
};
int v, g, cnt, tmp_cnt;
vector<int> vit, sum_vit, ans, tmp_vit, tmp_ans;
vector<holst> holst_vec;

void dfs(int sta){
    bool isvalid = true;
    for(int i = 0; i < v; ++ i){
        if(tmp_vit[i] < vit[i]){
            isvalid = false;
            break;
        }
    }
    if(isvalid){
        if(tmp_cnt < cnt){
            cnt = tmp_cnt;
            for(int i = 0; i < tmp_cnt; ++ i)
                ans[i] = tmp_ans[i];
        }
        return ;
    }
    if(tmp_cnt >= cnt)
        return ;
    for(int i = sta; i < g; ++ i){
        isvalid = true;
        for(int j = 0; j < v; ++ j){
            if(tmp_vit[j] + sum_vit[j] < vit[j]){
                isvalid = false;
                break;
            }
        }
        if(!isvalid)
            continue;
        for(int j = 0; j < v; ++ j){
            tmp_vit[j] += holst_vec[i].scop[j];
        }
        tmp_ans[tmp_cnt ++] = i + 1;
        dfs(i + 1);
        -- tmp_cnt;
        for(int j = 0; j < v; ++ j){
            tmp_vit[j] -= holst_vec[i].scop[j];
        }
    }
    return ;
}


int main(){
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");
    fin>>v;
    cnt = v + 1;
    vit.resize(v);
    sum_vit.resize(v);
    tmp_vit.resize(v);
    for(int i = 0; i < v; ++ i){
        fin>>vit[i];
        sum_vit[i] = 0;
    }
    fin>>g;
    holst_vec.resize(g);
    ans.resize(g);
    tmp_ans.resize(g);
    tmp_cnt = 0;
    for(int i = 0; i < g; ++ i){
        holst_vec[i].scop.resize(v);
        for(int j = 0; j < v; ++ j)
            fin>>holst_vec[i].scop[j];
    }
    for(int i = g - 1; i >= 0; -- i){
        for(int j = v - 1; j >= 0; -- j){
            sum_vit[j] += holst_vec[i].scop[j];
        }
    }
    for(int i = 0; i < g; ++ i){
        bool isvalid = true;
        for(int j = 0; j < v; ++ j){
            tmp_vit[j] = holst_vec[i].scop[j];
            if(sum_vit[j] < vit[j]){
                isvalid = false;
                break;
            }
        }
        if(!isvalid)
            break;
        tmp_ans[tmp_cnt ++] = i + 1;
        dfs(i + 1);
        tmp_cnt = 0;
    }
    fout<<cnt;
    for(int i = 0; i < cnt; ++ i)
        fout<<" "<<ans[i];
    fout<<endl;
    return 0;
}
