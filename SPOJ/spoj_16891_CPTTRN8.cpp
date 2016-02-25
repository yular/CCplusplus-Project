/*
 *
 * Tag: Implementation
 * Time: O(nm)
 * Space: O(1)
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
int n, m, r;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d%d",&n,&m,&r);
        for (int i = 0; i < n; ++ i) {
            int lc = r - 1, rc = 0;
            for (int j = 0; j < r; ++ j, -- lc, ++ rc) {
                for (int k = 0; k < m; ++ k) {
                    bool isstar = false;
                    for (int l = 0; l < r; ++ l) {
                        if (l == lc) {
                            printf("/");
                            isstar = true;
                        }else{
                            if (isstar) {
                                printf("*");
                            } else {
                                printf(".");
                            }
                        }
                    }
                    
                    isstar = true;
                    for (int l = 0; l < r; ++ l) {
                        if (l == rc) {
                            printf("\\");
                            isstar = false;
                        }else{
                            if (isstar) {
                                printf("*");
                            } else {
                                printf(".");
                            }
                        }
                    }
                }
                puts("");
            }
            
            lc = r - 1, rc = 0;
            for (int j = r; j < 2*r; ++ j, -- lc, ++ rc) {
                for (int k = 0; k < m; ++ k) {
                    bool isstar = false;
                    for (int l = 0; l < r; ++ l) {
                        if (l == rc) {
                            printf("\\");
                            isstar = true;
                        }else{
                            if (isstar) {
                                printf("*");
                            } else {
                                printf(".");
                            }
                        }
                    }
                    
                    isstar = true;
                    for (int l = 0; l < r; ++ l) {
                        if (l == lc) {
                            printf("/");
                            isstar = false;
                        }else{
                            if (isstar) {
                                printf("*");
                            } else {
                                printf(".");
                            }
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
