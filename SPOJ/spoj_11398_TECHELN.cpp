/*
 *
 * Tag: Math
 * Time: O(1)
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
const int N = 120;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
int dict[N];
int n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        if (n%4 <= 1) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
