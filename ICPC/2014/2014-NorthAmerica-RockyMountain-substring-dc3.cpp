/*
*
* Tag: String (Suffix Array - dc3)
* Time: O(n)
* Space: O(n)
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
using namespace std;
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
const int N = 20;
const int M = 1000005;
const int MOD = 10037;
int wa[M], wb[M], wss[M], wv[M];
char s[M];
int rmq[M], best[N][M], mm[M], ranks[M], h[M];
int r[M], sa[M];

int c0(int *r, int a, int b){
    return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}

int c12(int k, int *r, int a, int b){
    if (k == 2) {
        return r[a] < r[b] || (r[a] == r[b] && c12(1, r, a + 1, b + 1));
    } else {
        return r[a] < r[b] || (r[a] == r[b] && wv[a + 1] < wv[b + 1]);
    }
}

void sorts(int *r, int *a, int *b, int n, int m){
    for (int i = 0; i < n; ++ i) {
        wv[i] = r[a[i]];
    }
    for (int i = 0; i < m; ++ i) {
        wss[i] = 0;
    }
    for (int i = 0; i < n; ++ i) {
        ++ wss[wv[i]];
    }
    for (int i = 1; i < m; ++ i) {
        wss[i] += wss[i - 1];
    }
    for (int i = n - 1; i >= 0; -- i) {
        b[--wss[wv[i]]] = a[i];
    }
    return ;
}

void dc3(int *r, int *sa, int n, int m){
    int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1)/3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for (i = 0; i < n;  ++ i) {
        if (i%3) {
            wa[tbc ++] = i;
        }
    }
    sorts(r + 2, wa, wb, tbc, m);
    sorts(r + 1, wb, wa, tbc, m);
    sorts(r, wa, wb, tbc, m);
    for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; ++ i) {
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i])?p-1:p++;
    }
    if (p < tbc) {
        dc3(rn, san, tbc, p);
    } else {
        for (i = 0; i < tbc; ++ i) {
            san[rn[i]] = i;
        }
    }
    for (i = 0; i < tbc; ++ i) {
        if (san[i] < tb) {
            wb[ta ++] = san[i]*3;
        }
    }
    if (n%3 == 1) {
        wb[ta ++] = n - 1;
    }
    sorts(r, wb, wa, ta, m);
    for (i = 0; i < tbc; ++ i) {
        wv[wb[i] = G(san[i])] = i;
    }
    for (i = 0, j = 0, p = 0; i < ta && j < tbc; ++ p) {
        sa[p] = c12(wb[j]%3, r, wa[i], wb[j])?wa[i ++]:wb[j ++];
    }
    for (; i < ta; ++ p) {
        sa[p] = wa[i ++];
    }
    for (; j < tbc; ++ p) {
        sa[p] = wb[j ++];
    }
    return ;
}

void calheight(int *r, int *sa, int n){
    int i, j, k = 0;
    for (i = 1; i <= n; ++ i) {
        ranks[sa[i]] = i;
    }
    for (i = 0; i < n; h[ranks[i ++]] = k) {
        for (k?k--:0, j = sa[ranks[i] - 1]; r[i + k] == r[j + k]; ++ k) ;
    }
    return ;
}

int askrmq(int a, int b){
    int t;
    t = mm[b - a + 1];
    b -= (1<<t)-1;
    a = best[t][a];
    b = best[t][b];
    return rmq[a] < rmq[b]?a:b;
}

int lcp(int a, int b){
    a = ranks[a];
    b = ranks[b];
    if (a > b) {
        swap(a, b);
    }
    return h[askrmq(a + 1, b)];
}

int main(){

    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",s);
        int n = strlen(s);
        memset(r, 0, sizeof(r));
        for (int i = 0; i < n; ++ i) {
            r[i] = (int)s[i];
        }
        dc3(r, sa, n + 1, 256);
        calheight(r, sa, n);
        //initrmq(n);
        int ans = 0;
        for (int i = 2; i <= n; ++ i) {
            if (h[i] > h[i - 1]) {
                ans += (h[i] - h[i - 1]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
