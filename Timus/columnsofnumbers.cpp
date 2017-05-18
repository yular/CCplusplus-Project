/*
*
* Tag: Implementation
* Time: O(n)
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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 1530000;
const int M = 150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, k, arr[M], ans[M][M];

void init(){
    for (int i = 0; i < M; ++ i) {
        for (int j = 0; j < M; ++ j) {
            ans[i][j] = -1;
        }
    }
}

int calc(int v){
    int res = 0;
    if (v < 10) {
        res = 3;
    } else if (v < 100) {
        res = 2;
    } else {
        res = 1;
    }
    return res;
}

int main(){
    init();
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&arr[i]);
    }
    int m = (n%k == 0 ? n/k : ( n/k + 1));
    int r = 0, c = -1;
    for (int i = 0; i < n; ++ i) {
        if (r%m == 0) {
            ++ c;
            r = 0;
        }
        ans[r ++][c] = arr[i];
    }
    r = c = 0;
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < k; ++ j) {
            if (ans[i][j] == -1) {
                break;
            }
            int cnt = calc(ans[i][j]);
            for (int j = 0; j < cnt; ++ j) {
                printf(" ");
            }
            printf("%d",ans[i][j]);
        }
        puts("");
    }
    return 0;
}
