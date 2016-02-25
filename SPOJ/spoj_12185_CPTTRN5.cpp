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
        for (int i = 0; i <= m*(r + 1); ++ i) {
            printf("*");
        }
        puts("");
        for (int i = 0; i < n; ++ i) {
            if (i%2 == 0) {
                
                int lc = 0, rc = r - 1;
                for (int k = 0; k < r; ++ k, ++ lc, -- rc){
                    printf("*");
                    for (int j = 0; j < m; ++ j) {
                        if (j%2 == 0) {
                            for (int l = 0; l < r; ++ l) {
                                if (l == lc) {
                                    printf("\\");
                                }else{
                                    printf(".");
                                }
                            }
                        } else {
                            for (int l = 0; l < r; ++ l) {
                                if (l == rc) {
                                    printf("/");
                                }else{
                                    printf(".");
                                }
                            }
                        }
                        printf("*");
                    }
                    puts("");
                }
            
            } else {
                
                int lc = r - 1, rc = 0;
                for (int k = 0; k < r; ++ k, -- lc, ++ rc){
                    printf("*");
                    for (int j = 0; j < m; ++ j) {
                        if (j%2 == 0) {
                            for (int l = 0; l < r; ++ l) {
                                if (l == lc) {
                                    printf("/");
                                }else{
                                    printf(".");
                                }
                            }
                        } else {
                            for (int l = 0; l < r; ++ l) {
                                if (l == rc) {
                                    printf("\\");
                                }else{
                                    printf(".");
                                }
                            }
                        }
                        printf("*");
                    }
                    puts("");
                }
                
            }
            
            for (int j = 0; j <= m*(r + 1); ++ j) {
                printf("*");
            }
            puts("");
            
        }
        if (T) {
            puts("");
        }
    }
    return 0;
}
