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
const int N = 1020;
const int M = 10020;
const double eps = 1e-10;
int n, a, d;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d%d",&n,&a,&d);
        int ans = (2*a + (n - 1)*d)*n/2;
        printf("%d\n",ans);
    }
    return 0;
}
