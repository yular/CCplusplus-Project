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
const int N = 310;
const int M = 101010;
const double eps = 1e-10;
int n, m, w, h;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d%d%d",&n,&m,&h,&w);
        for (int i = 0; i <= n; ++ i) {
            for (int j = 0; j < h; ++ j) {
                for (int k = 0; k < (m + 1)*w + m; ++ k) {
                    if (k%(w + 1) == w) {
                        printf("|");
                    } else {
                        printf(".");
                    }
                }
                puts("");
            }
            if (i < n) {
                for (int j = 0; j < (m + 1)*w + m; ++ j) {
                    if (j%(w + 1) == w) {
                        printf("+");
                    } else {
                        printf("-");
                    }
                }
            }
            puts("");
        }
        if (T) {
            puts("");
        }
    }
    return 0;
}
