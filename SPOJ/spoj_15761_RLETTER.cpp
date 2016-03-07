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
char s[N],a[N],b[N];
int ans;

int main() {
    scanf("%s%s%s",s,a,b);
    for (int i = 0; s[i]; ++ i) {
        if (s[i] == a[0]) {
            s[i] = b[0];
        }
    }
    puts(s);
    return 0;
}
