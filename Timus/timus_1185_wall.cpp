/*
*
* Tag: Geometry
* Time: O(nlgn)
* Space: O(n)
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<climits>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#include<cmath>
#include<list>
#include<sstream>
using namespace std;
const int M = 10300;
const int N = 1000010;
const double eps = 1e-8;
const double dinf = 1e15;
const double PI = acos(-1.0);
const int MOD = 100000007;
pair<int,int> pnts[M];
int r, n, top, stk[M];

int dis( const pair<int,int> &a, const pair<int,int> &b) {
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

int crossMultiply( const pair<int,int> &p0, const pair<int,int> &p1, const pair<int,int> &p2 ){
    return (p1.first - p0.first)*(p2.second - p0.second) - (p2.first - p0.first)*(p1.second - p0.second);
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    int v = crossMultiply(pnts[0], a, b);
    if(v < 0)
        return false;
    else if(v == 0 && dis(pnts[0], a) - dis(pnts[0], b) > 0)
        return false;
    else
        return true;
}

void graham() {
    top = 2;
    stk[0] = 0, stk[1] = 1, stk[2] = 2;
    for(int i = 3; i < n; ++ i){
        while( crossMultiply(pnts[i], pnts[stk[top]], pnts[stk[top - 1]]) > 0 && top > 0 )
            -- top;
        stk[ ++ top] = i;
    }
}

int main(){
    double ans = 0;
    int idx = 0;
    scanf("%d%d",&n,&r);
    for(int i = 0; i < n; ++ i){
        scanf("%d%d",&pnts[i].first,&pnts[i].second);
        if(pnts[i].second < pnts[idx].second || (pnts[i].second == pnts[idx].second && pnts[i].first < pnts[idx].first)){
            idx = i;
        }
    }
    swap(pnts[idx], pnts[0]);
    sort(pnts + 1, pnts + n, cmp);
    graham();
    for(int i = 0; i < top; ++ i){
        ans += sqrt(dis(pnts[ stk[i] ], pnts[ stk[i+1] ]));
    }
    ans += sqrt(dis( pnts[stk[0] ], pnts[ stk[top] ] ));
    ans += 2*PI*r;
    printf("%.lf\n",ans);
    return 0;
}
