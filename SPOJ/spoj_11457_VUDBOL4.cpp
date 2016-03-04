/*
 *
 * Tag: Implementation
 * Time: O(n^2)
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 200;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
char s[N][N], t[N][N];
int n;

int main() {
    while (scanf("%d",&n) == 1 && n) {
        memset(t, 0, sizeof(t));
        for (int i = 0; i < n; ++ i) {
            scanf("%s",s[i]);
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                t[2*i][2*j] = t[2*i][2*j + 1] = t[2*i + 1][2*j] = t[2*i + 1][2*j + 1] = s[i][j];
            }
        }
        for (int i = 0; i < 2*n; ++ i) {
            puts(t[i]);
        }
    }
    return 0;
}
