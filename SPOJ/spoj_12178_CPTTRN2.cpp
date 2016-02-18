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
int n, m;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; ++ i) {
            if (i == 0 || i == n - 1) {
                for (int j = 0; j < m; ++ j) {
                    printf("*");
                }
            } else {
                for (int j = 0; j < m; ++ j) {
                    if (j == 0 || j == m - 1) {
                        printf("*");
                    } else {
                        printf(".");
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
