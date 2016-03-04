/*
 *
 * Tag: Implementation
 * Time: O(1)
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
const int N = 100020;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
char s[N];

int main() {
    scanf("%s",s);
    if (s[0] >= '0' && s[0] <= '9') {
        puts("number");
    } else {
        puts("word");
    }
    return 0;
}
