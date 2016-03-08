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
char s[N];

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",s);
        int cnt = 0;
        for (int i = 0; s[i]; ++ i) {
            if (s[i] >= 'a' && s[i] <= 'z' && s[i + 1] && s[i + 1] >= 'A' && s[i + 1] <= 'Z') {
                ++ cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
