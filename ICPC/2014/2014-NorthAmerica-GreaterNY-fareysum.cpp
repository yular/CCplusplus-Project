/*
*
* Tag: Math
* Time: ?
* Space: ?
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
const int N = 30;
const int M = 10205;
const int MOD = 10037;
const double eps = 1e-6;
int n, m;
int prim[M], phi[M], fareyCnt[M];
int lastFarey = 0, primfact[N], factCnts[20];

void init(){
    for (int i = 0; i <= 10000; ++ i) {
        prim[i] = 1;
        fareyCnt[i] = 0;
    }
    for (int i = 2; i <= 10000; ++ i) {
        if (prim[i] == 1) {
            for (int j = i*2; j <= 10000;  j += i ) {
                if (prim[j] == 1) {
                    prim[j] = i;
                }
            }
        }
    }
    fareyCnt[1] = 2;
    lastFarey = 1;
}

int GetPhi(int val){
    int notfound, i, res, cur, lastfact = 0;
    if (prim[val] == 1) {
        return (val - 1);
    }
    while (val > 1) {
        cur = prim[val];
        if (cur == 1) {
            cur = val;
        }
        for (notfound = 1, i = 0; i < lastfact && notfound; ++ i) {
            if (cur == primfact[i]) {
                notfound = 0;
                ++ factCnts[i];
                break;
            }
        }
        if (notfound) {
            primfact[lastfact] = cur;
            factCnts[lastfact] = 1;
            ++ lastfact;
        }
        val = val/cur;
    }
    res = 1;
    for (i = 0; i < lastfact; ++ i) {
        for (cur = 1; cur < factCnts[i]; ++ cur) {
            res *= primfact[i];
        }
        res *= (primfact[i] - 1);
    }
    return res;
}

int fareysum(int order, int *pnum, int *pdenom){
    int j;
    if (order <= lastFarey) {
        return fareyCnt[order];
    }
    for (j = lastFarey; j < order; ++ j) {
        fareyCnt[j + 1] = fareyCnt[j] + GetPhi(j + 1);
    }
    lastFarey = order;
    
    j = 3*fareyCnt[order] - 4;
    if ((j&1) == 0) {
        *pnum = j/2;
        *pdenom = 1;
    } else {
        *pnum = j;
        *pdenom = 2;
    }
    return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    init();
    while (T --) {
        scanf("%d%d",&n, &m);
        int num = 0, denom = 0;
        fareysum(m, &num, &denom);
        if (denom == 1) {
            printf("%d %d\n",n, num);
        } else {
            printf("%d %d/%d\n",n,num,denom);
        }
    }
    return 0;
}
