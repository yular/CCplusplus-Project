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
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
char chess[M][M];
pair<int, int> cp[2];
int n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        for (int i = 0; i < 8; ++ i) {
            scanf("%s",chess[i]);
        }
        int id = 0;
        for (int i = 0; i < 8; ++ i) {
            for (int j = 0; j < 8; ++ j) {
                if (chess[i][j] == 'B') {
                    cp[id].first = i;
                    cp[id ++].second = j;
                }
            }
        }
        if (abs(cp[0].first - cp[1].first) == abs(cp[0].second - cp[1].second)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
