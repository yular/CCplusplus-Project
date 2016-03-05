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
const int N = 3000200;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
int m;

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&m);
        printf("Case %d: ", cas++);
        if (m >= 80) {
            puts("A+");
        } else if ( m >= 75) {
            puts("A");
        } else if (m >= 70) {
            puts("A-");
        } else if (m >= 65) {
            puts("B+");
        } else if (m >= 60) {
            puts("B");
        } else if (m >= 55) {
            puts("B-");
        } else if (m >= 50) {
            puts("C");
        } else if (m >= 45) {
            puts("D");
        } else {
            puts("F");
        }
    }
    return 0;
}
