/*
*
* Tag: Grap Theory
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
const int N = 100200;
const int M = 210;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
enum direction {NORTH, EAST, SOUTH, WEST};
struct point {
    int x, y;
    point(int xx= 0, int yy = 0) :x(xx), y(yy) {}
    void setval(int xx, int yy) { x = xx; y = yy; }
    bool operator == (const point &a) const {
        return x == a.x && y == a.y;
    }
};
struct state{
    int d[2];
    point pt[2];
    state() { d[0] = d[1] = NORTH; }
    bool operator < (const state &s) const {
        return memcmp(this, &s, sizeof(state)) < 0;
    }
};
map<state, bool> h;
string mp[M];

bool meet(state &s){
    return s.pt[0] == s.pt[1];
}

void nextState(state &s){
    point npt[2];

    for(int i = 0; i < 2; ++ i){
        switch(s.d[i]){
            case NORTH:
                npt[i].setval(s.pt[i].x - 1, s.pt[i].y);
                break;
            case EAST:
                npt[i].setval(s.pt[i].x, s.pt[i].y + 1);
                break;
            case SOUTH:
                npt[i].setval(s.pt[i].x + 1, s.pt[i].y);
                break;
            case WEST:
                npt[i].setval(s.pt[i].x, s.pt[i].y - 1);
                break;
        }

        if(npt[i].x >= 0 && npt[i].x < 10 && npt[i].y >= 0 && npt[i].y < 10 && mp[npt[i].x][npt[i].y] == '.'){
            s.pt[i] = npt[i];
        }else{
            s.d[i] = (s.d[i] + 1)%4;
        }
    }
}

int main(){
    state s;

    for(int i = 0; i < 10; ++ i){
        fin>>mp[i];
        for(int j = 0; j < 10; ++ j){
            if(mp[i][j] == 'F' || mp[i][j] == 'C'){
                int t = (mp[i][j] - 'C' == 0 ? 0 : 1);
                s.pt[t].setval(i, j);
                mp[i][j] = '.';
            }
        }
    }
    int ans = 0;
    h[s] = true;
    while(!meet(s)){
        nextState(s);
        if(h[s]){
            ans = 0;
            break;
        }
        h[s] = true;
        ++ ans;
    }
    fout<<ans<<endl;
    return 0;
}
