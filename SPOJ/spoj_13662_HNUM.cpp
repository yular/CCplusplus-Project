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
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
int n;

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        printf("Case #%d: ",cas ++);
        if (n%2 == 0 && n%3 == 0 && n%5 == 0) {
            puts("H-Number");
        } else {
            puts("Not H-Number");
        }
    }
    return 0;
}
