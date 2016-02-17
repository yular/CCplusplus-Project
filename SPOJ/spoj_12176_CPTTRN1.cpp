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
const int N = 1010;
const int M = 101010;
const double eps = 1e-10;
int n, m;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        bool star = true;
        for (int i = 0; i < n; ++ i) {
            if (i%2 == 0) {
                star = true;
            } else {
                star = false;
            }
            for (int j = 0; j < m; ++ j) {
                if (star) {
                    printf("*");
                } else {
                    printf(".");
                }
                star = star?false:true;
            }
            puts("");
        }
        if (T) {
            puts("");
        }
    }
    return 0;
}
