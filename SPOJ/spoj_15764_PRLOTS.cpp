/*
 *
 * Tag: Implementation
 * Time: O(n)
 * Space: O(n)
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
const int N = 1033;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
char s[N], t[N];

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",s);
        memset(t, 0, sizeof(t));
        for (int i = 0; s[i]; ++ i) {
            int v;
            scanf("%d",&v);
            t[i] = s[v - 1];
        }
        puts(t);
    }
    return 0;
}
