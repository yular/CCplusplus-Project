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
        for (int i = 0; i < n; ++ i) {
            if (i == 0) {
                for (int j = 0; j < (w + 1)*m + 1; ++ j) {
                    printf("*");
                }
                puts("");
            }
            for (int j = 0; j < h + 1; ++ j) {
                if (j == h) {
                    for (int k = 0; k < (w + 1)*m + 1; ++ k) {
                        printf("*");
                    }
                } else {
                    for (int k = 0; k < (w + 1)*m + 1; ++ k) {
                        if (k%(w + 1) == 0) {
                            printf("*");
                        } else {
                            printf(".");
                        }
                    }
                }
                puts("");
            }
        }
        if (T) {
            puts("");
        }
    }
    return 0;
}
