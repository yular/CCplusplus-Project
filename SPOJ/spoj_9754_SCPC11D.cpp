/*
 *
 * Tag: Geometry
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
const int N = 10020;
const int M = 1030000;
const double eps = 1e-10;
int a[3];

int main() {
    while (scanf("%d%d%d",&a[0],&a[1],&a[2]) == 3) {
        if ((a[0] | a[1] | a[2]) == 0) {
            break;
        }
        sort(a, a + 3);
        if (a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) {
            puts("right");
        } else {
            puts("wrong");
        }
    }
    return 0;
}
