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
const int N = 1000200;
const int M = 1030;
const long long MOD = 1000000007;
const double eps = 1e-10;
char s[M], t[M];

int main() {
    scanf("%s%s",s,t);
    int cnt = 0;
    for (int i = 0; s[i]; ++ i) {
        if (s[i] == t[0]) {
            ++ cnt;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
