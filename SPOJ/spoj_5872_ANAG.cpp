/*
 *
 * Tag: Sort
 * Time: O(nlgn)
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
const int N = 1500;
const int M = 120;
const double eps = 1e-10;
char s[M], t[M];

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s%s",s, t);
        int n = strlen(s), m = strlen(t);
        sort(s, s + n);
        sort(t, t + m);
        if (strcmp(s, t) == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
