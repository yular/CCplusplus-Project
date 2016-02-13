/*
*
* Tag: Geometry
* Time: O(nlgn)
* Space: O(n)
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 1010;
const int M = 101010;
const double eps = 1e-10;
struct point{
    pair<int, int> p;
    int idx;
}pnts[M], stks[M];
int n, top;
//pair<int, int> pnt[M], stk[M];
unordered_map<int, unordered_set<int>> dict;
double ans;
bool vis[M];

double dis(const pair<int, int> &a, const pair<int, int> &b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double crossmulti(const pair<int, int> &p0, const pair<int, int> &p1, const pair<int, int> &p2){
    return (p1.first - p0.first)*(p2.second - p0.second) - (p2.first - p0.first)*(p1.second - p0.second);
}

bool cmp(const point &p, const point &q){
    double k = crossmulti(pnts[0].p, p.p, q.p);
    if (k < -eps) {
        return 0;
    } else if (fabs(k) < eps && (dis(p.p, pnts[0].p) - dis(q.p, pnts[0].p)) > eps) {
        return 0;
    } else {
        return 1;
    }
}

void removepnt(){
    int id = 1;
    for (int i = 2; i <= top; ++ i) {
        double d = crossmulti(stks[id].p, stks[i].p, stks[(i + 1)%(top + 1)].p);
        if (fabs(d - 0.0) < eps) {
            vis[i] = 1;
        } else {
            id = i;
        }
    }
}

void covexhull(){
    if (n == 1) {
        printf("%.2lf\n",ans);
        printf("1\n");
        return ;
    }
    int k = 1, miny = pnts[0].p.second, idx = 0;
    for (int i = 1; i < n; ++ i) {
        if (pnts[i].p.second < miny) {
            miny = pnts[i].p.second;
            idx = i;
        } else if (fabs(pnts[i].p.second - miny) < eps && pnts[i].p.first < pnts[idx].p.first) {
            idx = i;
        }
    }
    if (n == 2) {
        ans = dis(pnts[0].p, pnts[1].p)*2;
        printf("%.2lf\n",ans);
        printf("%d %d\n",pnts[1].idx, pnts[0].idx);
        return ;
    }
    point tmp = pnts[idx];
    pnts[idx] = pnts[0];
    pnts[0] = tmp;
    sort(pnts + 1, pnts + n, cmp);
    stks[0] = pnts[n - 1];
    stks[1] = pnts[0];
    top = 1;
    k = 1;
    while (k <= n - 1) {
        double d = crossmulti(stks[top].p, stks[top - 1].p, pnts[k].p);
        if (d < 0 || fabs(d - 0.0) < eps) {
            ++ top;
            stks[top] = pnts[k];
            ++ k;
        } else {
            -- top;
        }
    }
    
    for (int i = 0; i <= top; ++ i) {
        ans += dis(stks[i].p, stks[(i + 1)%(top + 1)].p);
    }
    printf("%.2lf\n",ans);
    removepnt();
    for (int i = 1; i < top; ++ i) {
        if (!vis[i]) {
            printf("%d ",stks[i].idx);
        }
    }
    printf("%d\n",stks[top].idx);
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        int f, s, m = 0;
        dict.clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d",&f,&s);
            if (dict.find(f) == dict.end() || dict[f].find(s) == dict[f].end()) {
                //pnt[m].first = f;
                //pnt[m].second = s;
                pnts[m].p.first = f;
                pnts[m].p.second = s;
                pnts[m].idx = i + 1;
                ++ m;
                dict[f].insert(s);
            }
        }
        n = m;
        ans = 0;
        covexhull();
        if (T) {
            puts("");
        }
    }
    return 0;
}
