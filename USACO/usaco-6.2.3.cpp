/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n^2)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 1001;
const int M = 200100;
//const int INF = 1<<29;
struct rect{
    int px, py, qx, qy, col;
}r[N];
int a, b, n, cur_c;
int sq[N];

void cal(int px, int py, int qx, int qy, int pos){
    do{
        ++ pos;
    }while (pos <= n && (r[pos].px >= qx || r[pos].py >= qy || r[pos].qx <= px || r[pos].qy <= py));
    
    if (pos > n) {
        sq[cur_c] += (qx - px)*(qy - py);
    } else {
        if (px < r[pos].px) {
            cal(px, py, r[pos].px, qy, pos);
            px = r[pos].px;
        }
        if (qx > r[pos].qx) {
            cal(r[pos].qx, py, qx, qy, pos);
            qx = r[pos].qx;
        }
        if (py < r[pos].py) {
            cal(px, py, qx, r[pos].py, pos);
        }
        if (qy > r[pos].qy) {
            cal(px, r[pos].qy, qx, qy, pos);
        }
    }
}

int main() {
//    freopen("rect1.in", "r", stdin);
//    freopen("rect1.out", "w", stdout);
    scanf("%d%d%d",&a,&b,&n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d%d%d%d%d",&r[i].px,&r[i].py,&r[i].qx,&r[i].qy,&r[i].col);
    }
    r[0].qx = a;
    r[0].qy = b;
    r[0].col = 1;
    for (int i = n; i >= 0; -- i) {
        cur_c = r[i].col;
        cal(r[i].px,r[i].py,r[i].qx,r[i].qy,i);
    }
    for (int i = 1; i < N; ++ i) {
        if (sq[i]) {
            printf("%d %d\n",i,sq[i]);
        }
    }
    return 0;
}
