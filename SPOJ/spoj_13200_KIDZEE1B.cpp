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
const int N = 3000200;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
int a[3];

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        printf("Case %d: ", cas++);
        int sum = a[0] + a[1] + a[2];
        printf("Sum of %d, %d and %d is %d\n",a[0],a[1],a[2],sum);
    }
    return 0;
}
