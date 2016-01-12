/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 110;
const int M = 1000020;
int n, m;
long long comb[N][N];

void init(){
    comb[1][0] = comb[1][1] = 1;
    for (int i = 2; i <= N/2; ++ i) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++ j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

int main() {
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        printf("%lld %lld\n",comb[n][m - 1], comb[n][m]*m/n);
    }
    return 0;
}
