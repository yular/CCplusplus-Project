/*
 *
 * Tag: Implementation
 * Time: O(nm)
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
const int N = 500;
const int M = 20;
const double eps = 1e-10;
int n;
char mp[N][N];

void init(){
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            mp[i][j] = '.';
        }
    }
}

bool canMove(int x, int y){
    if (x == 0 || (x > 2 && mp[x - 2][y] == '.' && mp[x - 1][y] == '.')) {
        return true;
    }
    if (x < n - 1 && mp[x + 1][y] == '.' && mp[x + 2][y] == '.') {
        return true;
    }
    if (y == 0 || (y > 2 && mp[x][y - 2] == '.' && mp[x][y - 1] == '.')) {
        return true;
    }
    if (y < n - 1 && mp[x][y + 1] == '.' && mp[x][y + 2] == '.') {
        return true;
    }
    return false;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        init();
        int r = 0, c = 0;
        int dir = 1;
        while (1) {
            if (dir == 1) {
                if (r + 1 >= n || mp[r + 2][c] == '*') {
                    dir = 0;
                } else {
                    mp[r][c] = '*';
                    ++ r;
                }
            }
            if (dir == 0) {
                if (c + 1 >= n || mp[r][c + 2] == '*') {
                    dir = 3;
                } else {
                    mp[r][c] = '*';
                    ++ c;
                }
            }
            if (dir == 3) {
                if (r - 1 < 0 || mp[r - 2][c] == '*') {
                    dir = 2;
                } else {
                    mp[r][c] = '*';
                    -- r;
                }
            }
            if (dir == 2) {
                if (c - 1 < 0 || mp[r][c - 2] == '*') {
                    dir = 1;
                } else {
                    mp[r][c] = '*';
                    -- c;
                }
            }
            
            if (!canMove(r, c)) {
                if (n%2) {
                    mp[r][c] = '*';
                }
                break;
            }
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
