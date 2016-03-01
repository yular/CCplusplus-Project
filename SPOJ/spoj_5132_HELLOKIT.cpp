/*
 *
 * Tag: Implementation
 * Time: O(nm) where m is the final length of string
 * Space: O(m)
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
char s[N], inp[M];
int n;

int main() {
    while (scanf("%s",inp) == 1) {
        int len = strlen(inp);
        if (len == 1 && inp[0] == '.') {
            break;
        }
        scanf("%d",&n);
        memset(s, 0, sizeof(s));
        int slen = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < len; ++ j, ++ slen) {
                s[slen] = inp[j];
            }
        }
        int sta = 0;
        for (int i = 0; i < len; ++ i, ++ sta) {
            int k = sta;
            for (int j = 0; j < slen; ++ j, k = (k + 1)%slen) {
                printf("%c",s[k]);
            }
            puts("");
        }
    }
    return 0;
}
