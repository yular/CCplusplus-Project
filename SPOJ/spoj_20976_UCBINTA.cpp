/*
 *
 * Tag: Math
 * Time: O(n)
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
const int N = 1000200;
const int M = 1010;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n;
int a[M][M], ans[M];

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            scanf("%d",&a[i][j]);
        }
    }
    if (n == 2) {
        printf("1 %d\n",a[0][1] - 1);
    } else {
        ans[1] = (a[0][1] + a[1][2] - a[0][2])/2;
        ans[0] = a[0][1] - ans[1];
        for (int i = 2; i < n; ++ i) {
            ans[i] = a[0][i] - ans[0];
        }
        bool isfirst = true;
        for (int i = 0; i < n; ++ i) {
            if (!isfirst) {
                printf(" ");
            }
            printf("%d",ans[i]);
            isfirst = false;
        }
        puts("");
    }
    return 0;
}
