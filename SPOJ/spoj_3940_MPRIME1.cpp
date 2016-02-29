/*
 *
 * Tag: Number Theory
 * Time: O(n^2)
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
const int N = 15000;
const int M = 120;
const double eps = 1e-10;
int ans[N], n;
int prim[N], num, sum[N], bnd;

void init(){
    num = 4;
    prim[0] = 2;
    prim[1] = 3;
    prim[2] = 5;
    prim[3] = 7;
    for (int i = 11; i < 11003; ++ i) {
        bool isprim = true;
        for (int j = 2; j <= sqrt(i); ++ j) {
            if (i%j == 0) {
                isprim = false;
                break;
            }
        }
        if (isprim) {
            prim[num ++] = i;
        }
    }
    memset(ans, 0, sizeof(ans));
    sum[0] = 2;
    for (int i = 1; i < num; ++ i) {
        sum[i] = sum[i - 1] + prim[i];
    }
    ans[2] = 1;
    for (int i = 1; i < num; ++ i) {
        for (int j = 0; j < i; ++ j) {
            if (sum[i] - sum[j] <= 11000) {
                ++ ans[sum[i] - sum[j]];
            }
        }
        if (sum[i] <= 11000) {
            ++ ans[sum[i]];
        }
    }
}

int main() {
    init();
    while(scanf("%d",&n) && n) {
        printf("%d\n",ans[n]);
    }
    return 0;
}
