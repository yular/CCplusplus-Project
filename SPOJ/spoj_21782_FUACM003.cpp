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
const int N = 1000200;
const int M = 1030;
const long long MOD = 1000000007;
const double eps = 1e-10;
int a,n;

int main() {
    scanf("%d",&n);
    bool isfun = true;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&a);
        if (a%2 == 0) {
            isfun = false;
        }
    }
    if (isfun) {
        puts("Oh! Fun");
    } else {
        puts("No");
    }
    return 0;
}
