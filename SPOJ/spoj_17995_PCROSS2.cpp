/*
 *
 * Tag: Implementation
 * Time: max(O(n), O(m))
 * Space: O(nm)
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
const int N = 310;
const int M = 101010;
const double eps = 1e-10;
int n, m, x, y;
char mp[N][N];

void init(){
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            mp[i][j] = '.';
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d%d%d",&n,&m,&x,&y);
        init();
        -- x;
        -- y;
        for (int i = x, j = y; i >= 0 && j >= 0; -- i, -- j) {
            mp[i][j] = '*';
        }
        for (int i = x, j = y; i < n && j >= 0; ++ i, -- j) {
            mp[i][j] = '*';
        }
        for (int i = x, j = y; j < m && i >= 0; ++ j, -- i) {
            mp[i][j] = '*';
        }
        for (int i = x, j = y; i < n && j < m; ++ j, ++ i) {
            mp[i][j] = '*';
        }
        for (int i = 0; i < n; ++ i) {
            puts(mp[i]);
        }
        if (T) {
            puts("");
        }
    }
    return 0;
}
