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
const int N = 10000300;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
char s[N];

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",s);
        int odd = 0, even = 0;
        for (int i = 0; s[i]; ++ i) {
            int val = s[i] - '0';
            if (val%2 == 0) {
                ++ even;
            } else {
                ++ odd;
            }
        }
        if (odd >= even) {
            puts("odd");
        } else {
            puts("even");
        }
    }
    return 0;
}
