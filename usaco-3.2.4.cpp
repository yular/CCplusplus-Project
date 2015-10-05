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
const int M = 900;
ifstream fin("ratios.in");
ofstream fout("ratios.out");
struct node{
    int x, y, z;
}s[4];
int ans[4];

int main(){
    for(int i = 0; i < 4; ++ i)
        fin>>s[i].x>>s[i].y>>s[i].z;
    ans[0] = INF;
    for(int i = 0; i <= 100; ++ i){
        for(int j = 0; j <= 100; ++ j){
            for(int k = 0; k <= 100; ++ k){
                if ((!s[0].x || (s[1].x*i+s[2].x*j+s[3].x*k)%s[0].x==0) && (!s[0].y || (s[1].y*i+s[2].y*j+s[3].y*k)%s[0].y==0) && (!s[0].z || (s[1].z*i+s[2].z*j+s[3].z*k)%s[0].z==0)){
                    int tmp = 0;
                    if(s[0].x)
                        tmp = (s[1].x*i+s[2].x*j+s[3].x*k)/s[0].x;
                    else{
                        if(s[1].x*i+s[2].x*j+s[3].x*k)
                            continue;
                        if(s[0].y)
                            tmp = (s[1].y*i+s[2].y*j+s[3].y*k)/s[0].y;
                        else{
                            if(s[1].y*i+s[2].y*j+s[3].y*k)
                                continue;
                            if(s[0].z)
                                tmp = (s[1].z*i+s[2].z*j+s[3].z*k)/s[0].z;
                        }
                    }
                    if(!tmp)
                        continue;
                    if(s[1].y*i+s[2].y*j+s[3].y*k == tmp*s[0].y){
                        if(s[1].z*i+s[2].z*j+s[3].z*k == tmp*s[0].z){
                            if(ans[0] > tmp){
                                ans[1] = i;
                                ans[2] = j;
                                ans[3] = k;
                                ans[0] = tmp;
                            }
                        }
                    }
                }
            }
        }
    }
    if(ans[0] == INF)
        fout<<"NONE"<<endl;
    else{
        fout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[0]<<endl;
    }
    return 0;
}
