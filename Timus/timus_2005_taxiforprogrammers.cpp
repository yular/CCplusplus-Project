/*
*
* Tag: DFS
* Time: O(n!)
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
const int N = 20;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int mp[N][N], path[N], tmppath[N];
bool vis[N];

int main(){
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 5; ++ i) {
        tmppath[i] = i;
        for (int j = 0; j < 5; ++ j) {
            scanf("%d",&mp[i][j]);
        }
    }
    int ans = INT_MAX;
    do {
        if (tmppath[3] + 1 != 3) {
            int sum = 0;
            for (int i = 1; i < 5; ++ i) {
                sum += mp[ tmppath[i - 1] ][ tmppath[i] ];
            }
            if (sum < ans) {
                ans = sum;
                for (int i = 0; i < 5; ++ i) {
                    path[i] = tmppath[i];
                }
            }
        }
    } while (next_permutation( tmppath + 1, tmppath + 4));
    printf("%d\n",ans);
    bool isfirst = true;
    for (int i = 0; i < 5; ++ i) {
        if (!isfirst) {
            printf(" ");
        }
        printf("%d",path[i] + 1);
        isfirst = false;
    }
    puts("");
    return 0;
}
