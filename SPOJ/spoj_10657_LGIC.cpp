/*
 *
 * Tag: Math
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
const int N = 500;
const int M = 20;
const double eps = 1e-10;
int n;

int main() {
    scanf("%d",&n);
    long long ans = 0, res = 1, pows = 1<<n;
    for (int i = 2; i <= n; ++ i) {
        res *= i;
    }
    ans = res - n + pows;
    printf("%lld\n",ans);
    return 0;
}
