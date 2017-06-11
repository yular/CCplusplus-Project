/*
* 
* Tag: Computation Geometry
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
#include<time.h>
using namespace std;
const int M = 260;
const int N = 500;
const double eps = 1e-8;
const double dinf = 1e15;
const double PI = acos(-1.0);
const int MOD = 100000007;
int n, top;
double r, ans;
pair<double, double> pnt[N], stk[N];

double dis(pair<double,double> a, pair<double,double> b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double crossmulti(pair<double,double> p0, pair<double,double> p1, pair<double,double> p2){
    return (p1.first - p0.first)*(p2.second - p0.second) - (p2.first - p0.first)*(p1.second - p0.second);
}

bool cmp(const pair<double,double> &p, const pair<double,double> &q){
    double k = crossmulti(pnt[0], p, q);
    if(k < -eps)
        return 0;
    else if(fabs(k) < eps && (dis(p, pnt[0]) - dis(q, pnt[0])) > eps)
        return 0;
    else
        return 1;
}

double circle(){
    return 2*PI*r;
}

void covex_hull(){
    int i, k, d, idx = 0;
    double miny = pnt[0].second;
    for(i = 1; i < n; ++ i){
        if(pnt[i].second < miny){
            miny = pnt[i].second;
            idx = i;
        }else if(fabs(pnt[i].second - miny) <= eps && pnt[i].first < pnt[idx].first){
            idx = i;
        }
    }
    pair<double,double> tmp;
    tmp = pnt[idx];
    pnt[idx] = pnt[0];
    pnt[0] = tmp;
    sort(pnt + 1, pnt + n, cmp);
    stk[0] = pnt[n - 1];
    stk[1] = pnt[0];
    top = 1;
    k = 1;
    while(k < n){
        double d = crossmulti(stk[top],stk[top-1],pnt[k]);
        if(d <= 0){
            ++ top;
            stk[top] = pnt[k];
            ++ k;
        }else
            -- top;
    }
    for(int i = 0; i < top; ++ i){
        ans += dis(pnt[i], pnt[(i + 1)%top]);
    }
}

int main(){
    scanf("%d%lf",&n,&r);
    for(int i = 0; i < n; ++ i){
        scanf("%lf%lf",&pnt[i].first,&pnt[i].second);
    }
    ans = 0;
    covex_hull();
    ans += circle();
    printf("%.2lf\n",ans);
    return 0;
}
