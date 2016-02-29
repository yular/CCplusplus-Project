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
const int N = 3000;
const int M = 120;
const double eps = 1e-10;
char s[M], ans[M];
int n;

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%s",&n,s);
        -- n;
        memset(ans, 0, sizeof(ans));
        int j = 0;
        for (int i = 0; s[i]; ++ i) {
            if (i != n) {
                ans[j ++] = s[i];
            }
        }
        printf("%d %s\n",cas++, ans);
    }
    return 0;
}
