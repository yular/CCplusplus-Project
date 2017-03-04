/*
*
* Tag: Graph
* Time: O(n^3)
* Space: O(n^2)
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
#include <map>
#include <set>
using namespace std;
const int N = 2020002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n;
int mp[M][M];

void floyd(){
    for (int k = 0; k < n; ++ k) {
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d",&mp[i][j]);
            }
        }
        floyd();
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                printf("%d ", mp[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
