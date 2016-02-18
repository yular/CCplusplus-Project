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
            if (i == 0) {
                for (int j = 0; j < 3*m + 1; ++ j) {
                    printf("*");
                }
                puts("");
            }
            for (int j = 0; j < 3; ++ j) {
                if (j == 2) {
                    for (int k = 0; k < 3*m + 1; ++ k) {
                        printf("*");
                    }
                } else {
                    for (int k = 0; k < 3*m + 1; ++ k) {
                        if (k%3 == 0) {
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
