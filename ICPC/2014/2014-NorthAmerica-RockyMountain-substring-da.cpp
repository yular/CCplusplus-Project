/*
*
* Tag: String (Suffix Array - da)
* Time: O(nlgn)
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
const int N = 20;
const int M = 1000005;
const int MOD = 10037;
int wa[M], wb[M], wc[M], wv[M];
char s[M];
int rmq[M], best[N][M], mm[M], ranks[M], h[M];
int r[M], sa[M];

int cmp(int *r, int a, int b, int l){
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int *sa, int n, int m){
    int *x = wa, *y = wb, *t;
    int j, p;
    for (int i = 0; i < m;  ++ i) {
        wc[i] = 0;
    }
    for (int i = 0; i < n; ++ i) {
        ++ wc[x[i] = r[i]];
    }
    for (int i = 1; i < m; ++ i) {
        wc[i] += wc[i - 1];
    }
    for (int i = n - 1; i >= 0; -- i) {
        sa[-- wc[x[i]]] = i;
    }
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
        int i;
        for (p = 0, i = n - j; i < n; ++ i) {
            y[p ++] = i;
        }
        for (i = 0; i < n; ++ i) {
            if (sa[i] >= j) {
                y[p ++] = sa[i] - j;
            }
        }
        for (i = 0; i < n; ++ i) {
            wv[i] = x[y[i]];
        }
        for (i = 0; i < m; ++ i) {
            wc[i] = 0;
        }
        for (i = 0; i < n; ++ i) {
            ++ wc[wv[i]];
        }
        for (i = 1; i < m; ++ i) {
            wc[i] += wc[i - 1];
        }
        for (i = n - 1; i >= 0; -- i) {
            sa[--wc[wv[i]]] = y[i];
        }
        for (t = x, x= y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; ++ i) {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j)?p - 1 : p ++;
        }
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

void initrmq(int n){
    int i, j, a, b;
    for (mm[0] = -1, i = 1; i <= n; ++ i) {
        mm[i] = ((i&(i-1))==0)?mm[i - 1] + 1:mm[i - 1];
    }
    for (i = 1; i <= n; ++ i) {
        best[0][i] = i;
    }
    for (i = 1; i <= mm[n]; ++ i) {
        for (j = 1; j <= n + 1 - (1<<j); ++ j) {
            a = best[i - 1][j];
            b = best[i - 1][j + (1<<(i - 1))];
            if (rmq[a] < rmq[b]) {
                best[i][j] = a;
            } else {
                best[i][j] = b;
            }
        }
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
        da(r, sa, n + 1, 256);
        calheight(r, sa, n);
        //initrmq(n);
        //test: lcp(2,3); //the longest common prefix between suffix rank 2 and 3
        int ans = 0;
     /*   for (int i = 1; i <= n; ++ i) {
            printf("%d ",h[i]);
        }
        puts(""); */
        for (int i = 2; i <= n; ++ i) {
            if (h[i] > h[i - 1]) {
                ans += (h[i] - h[i - 1]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
