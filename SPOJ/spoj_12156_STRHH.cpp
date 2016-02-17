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
const int N = 1010;
const int M = 101010;
const double eps = 1e-10;
char s[N];

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",s);
        int len = strlen(s);
        for (int i = 0; i < len/2; i += 2) {
            putchar(s[i]);
        }
        puts("");
    }
    return 0;
}
