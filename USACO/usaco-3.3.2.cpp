/*
*
* Tag: DP / Graph Theory
* Time: 6^5
* Space: 5^10
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
const int N = 10;
const int M = 1310;
ifstream fin("shopping.in");
ofstream fout("shopping.out");
struct offer{
    int p;
    int items[N];
}vec[M];
struct item{
    int c, k, p;
}itset[N];
int dp[N][N][N][N][N];
int s, b, n;
int dict[M], num;

void init(){
    num = 0;
    for(int i = 0; i < N; ++ i){
        for(int j = 0; j < N; ++ j){
            for(int k = 0; k < N; ++ k){
                for(int l = 0; l < N; ++ l){
                    for(int m = 0; m < N; ++ m){
                        dp[i][j][k][l][m] = INT_MAX;

                    }
                }
            }
        }
    }
    for(int i = 0; i < M; ++ i){
        dict[i] = -1;
    }
    for(int i = 0; i < N; ++ i){
        itset[i].k = 0;
        itset[i].p = 0;
    }
}

void noOffer(int soffer[]){
/*    for(int i = 0; i < 5; ++ i)
        cout<<soffer[i]<<" ";
    cout<<endl; */
    for(int i = 0; i < b; ++ i){
        for(int j = 1; j <= itset[i].k; ++ j){
            if(soffer[i] < j)
                break;
            int val[N];
            for(int k = 0; k < 5; ++ k){
                val[k] = soffer[k];
                if(i == k)
                    val[k] -= j;
            }
            dp[val[0]][val[1]][val[2]][val[3]][val[4]] = min(dp[val[0]][val[1]][val[2]][val[3]][val[4]],
                                                             dp[soffer[0]][soffer[1]][soffer[2]][soffer[3]][soffer[4]] + j*itset[i].p);
        }
    }
}

void useOffer(int soffer[]){
    int val[N];
    for(int i = 0; i < s; ++ i){
        bool canUse = true;
        for(int j = 0; j < 5; ++ j){
            if(vec[i].items[j] > soffer[j]){
                canUse = false;
                break ;
            }
        }
        if(canUse){
            memset(val, 0, sizeof(val));
            for(int j = 0; j < 5; ++ j){
                val[j] = soffer[j] - vec[i].items[j];
            }
            dp[val[0]][val[1]][val[2]][val[3]][val[4]] = min(dp[val[0]][val[1]][val[2]][val[3]][val[4]],
                                                             dp[soffer[0]][soffer[1]][soffer[2]][soffer[3]][soffer[4]] + vec[i].p);
        }
    }
}

int main(){
    init();
    fin>>s;
    for(int i = 0; i < s; ++ i){
        fin>>n;
        for(int j = 0; j < N; ++ j)
            vec[i].items[j] = 0;
        for(int j = 0; j < n; ++ j){
            int c, k;
            fin>>c>>k;
            if(dict[c] == -1)
                dict[c] = num ++;
            vec[i].items[dict[c]] = k;
        }
        fin>>vec[i].p;
    }
    fin>>b;
    for(int i = 0; i < b; ++ i){
        int c, k, p;
        fin>>c>>k>>p;
        if(dict[c] == -1)
            dict[c] = num ++;
        itset[dict[c]].k = k;
        itset[dict[c]].p = p;
    }
    dp[itset[0].k][itset[1].k][itset[2].k][itset[3].k][itset[4].k] = 0;
    for(int i = itset[0].k; i >= 0; -- i){
        for(int j = itset[1].k; j >= 0; -- j){
            for(int k = itset[2].k; k >= 0; -- k){
                for(int l = itset[3].k; l >= 0; -- l){
                    for(int m = itset[4].k; m >= 0; -- m){
                        if(!i && !j && !k && !l && !m)
                            break;
                        int soffer[] = {i, j, k, l, m};
                        noOffer(soffer);
                        useOffer(soffer);
                    }
                }
            }
        }
    }
    fout<<dp[0][0][0][0][0]<<endl;
    return 0;
}
