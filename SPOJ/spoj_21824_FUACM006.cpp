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
using namespace std;
const int N = 1000200;
const int M = 1030;
const long long MOD = 1000000007;
const double eps = 1e-10;
char s[M], t[M];

int main() {
    gets(s);
    memset(t, 0, sizeof(t));
    int id = 0;
    for (int i = 0; s[i]; ++ i) {
        if (s[i] >= '0' && s[i] <= '9') {
            continue;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            t[id ++] = s[i];
        } else {
            t[id ++] = '@';
        }
    }
    puts(t);
    return 0;
}
