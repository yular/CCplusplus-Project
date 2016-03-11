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
const int N = 2000011;
const int M = 1010;
const long long MOD = 1000000007;
const double eps = 1e-10;
char s[M];
int n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",s);
        int len = strlen(s);
        for (int i = len - 1; i >= 0; -- i) {
            printf("%c",s[i]);
        }
        puts("");
    }
    return 0;
}
