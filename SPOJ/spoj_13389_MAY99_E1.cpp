/*
 *
 * Tag: Hash
 * Time: O(n)
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
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
int cnt[M];
char s[N];

int main() {
    while (scanf("%s",s) == 1) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; s[i]; ++ i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                ++ cnt[s[i] - 'A'];
            } else {
                ++ cnt[s[i] - 'a' + 26];
            }
        }
        char ans = 0;
        int tmpcnt = 0;
        for (int i = 0; i < 60; ++ i) {
            if (cnt[i] > tmpcnt) {
                tmpcnt = cnt[i];
                if (i < 26) {
                    ans = (i + 'A');
                } else {
                    ans = ((i - 26) + 'a');
                }
            }
        }
        printf("%c\n",ans);
    }
    return 0;
}
