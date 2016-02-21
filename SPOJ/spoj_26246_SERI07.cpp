/*
 *
 * Tag: Math
 * Time: O(M)
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
const int N = 30010;
const int M = 101010;
const double eps = 1e-10;
int n;
int prim[M], num, p[M];
int ans[N];

void getprime(){
    num = 0;
    for (int i = 2; i < M; ++ i) {
        if (!prim[i]) {
            p[num ++] = i;
        }
        for (int j = 0; (j < num && i*p[j] < M); ++ j) {
            prim[i*p[j]] = 1;
            if (!(i%p[j])) {
                break;
            }
        }
    }
}

void init(){
    getprime();
//    printf("%d\n",p[num - 1]);
    int id = 0;
    for (int i = 0; i < 10010; ++ i) {
        ans[i] = (p[id]*p[id + 1]) + p[id + 2];
        id += 3;
    }
}


int main() {
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        bool isfirst = true;
        for (int i = 0; i < n; ++ i) {
            if (!isfirst) {
                printf(" ");
            }
            printf("%d",ans[i]);
            isfirst = false;
        }
        puts("");
    }
    return 0;
}
