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
const int N = 100010;
const int M = 10;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n;
char unit[M];

int main() {
    double ans = 0;
    scanf("%d%s",&n,unit);
    if (unit[0] == 'F') {
        ans = 5.0*(n - 32)/9.0;
        printf("%.2lf C\n",ans);
    } else {
        ans = 32+ 9.0*n/5.0;
        printf("%.2lf F\n",ans);
    }
    return 0;
}
