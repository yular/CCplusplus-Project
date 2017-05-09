/*
*
* Tag: Geometry
* Time: O(nlgn)
* Space: O(lgn)
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 33000;
const int M = 50;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
struct town{
    pair<long long, long long> loc;
    int id;
}pnt[N];
int n;

double dis(town a, town b){
    return sqrt( (a.loc.first - b.loc.first)*(a.loc.first - b.loc.first)*1.0 + (a.loc.second - b.loc.second)*(a.loc.second - b.loc.second) );
}

double crossmulti(town p0, town p1, town p2){
    return (p1.loc.first - p0.loc.first)*(p2.loc.second - p0.loc.second) - (p2.loc.first - p0.loc.first)*(p1.loc.second - p0.loc.second);
}

bool cmp(const town &a, const town &b){
    double v = crossmulti(pnt[0], a, b);
    if (v < -eps)
        return 0;
    else if ( fabs(v) < eps  && (dis(a, pnt[0]) - dis(b, pnt[0])) > eps )
        return 0;
    else
        return 1;
}

int main(){
    scanf("%d",&n);
    int idx = 0;
    long long miny = LLONG_MAX;
    for (int i = 0; i < n; ++ i) {
        scanf("%lld%lld",&pnt[i].loc.first,&pnt[i].loc.second);
        pnt[i].id = i + 1;
        if (miny > pnt[i].loc.second) {
            miny = pnt[i].loc.second;
            idx = i;
        } else if (miny == pnt[i].loc.second && pnt[idx].loc.first > pnt[i].loc.first) {
            idx = i;
        }
    }
    swap(pnt[0], pnt[idx]);
    sort(pnt + 1, pnt + n, cmp);
    for (int i = 0; i < n; i += 2) {
        printf("%d %d\n",pnt[i].id, pnt[i + 1].id);
    }
    return 0;
}
