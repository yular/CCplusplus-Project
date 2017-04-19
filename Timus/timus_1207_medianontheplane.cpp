/*
*
* Tag: Sort
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
const int N = 10050;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
struct point{
    double x, y;
    int id;
}pnt[N],tpnt;
int n;

bool cmp(point &a, point &b){
    double x1 = a.x - pnt[0].x, y1 = a.y - pnt[0].y;
    double x2 = b.x - pnt[0].x, y2 = b.y - pnt[0].y;
    if (x1*y2 - x2*y1 < 0) {
        return true;
    } else {
        return false;
    }
}

int main(){
    tpnt.x = tpnt.y = DOUBLEMAX;
    scanf("%d",&n);
    int idx = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
        pnt[i].id = i + 1;
        if (tpnt.x > pnt[i].x) {
            tpnt = pnt[i];
            idx = i;
        } else if (tpnt.x == pnt[i].x && tpnt.y > pnt[i].y ) {
            tpnt = pnt[i];
            idx = i;
        }
    }
    if (n == 2) {
        puts("1 2");
    } else {
        swap(pnt[0], pnt[idx]);
        sort(pnt + 1, pnt + n, cmp);
        int ans1 = pnt[0].id, ans2 = pnt[n/2].id;
        printf("%d %d\n",min(ans1, ans2), max(ans1, ans2));
    }
    return 0;
}
