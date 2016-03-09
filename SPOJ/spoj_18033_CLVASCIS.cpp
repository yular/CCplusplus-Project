/*
 *
 * Tag: Math
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
const int N = 110;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
int h, w;

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&h, &w);
        printf("Case #%d: %d , %d\n",cas++,h+w,h*w);
    }
    return 0;
}
