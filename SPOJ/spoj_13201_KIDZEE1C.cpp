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
int n;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        if (n%3 == 0) {
            printf("%d is a multiple of 3\n",n);
        } else {
            printf("%d is not a multiple of 3\n",n);
        }
    }
    return 0;
}
