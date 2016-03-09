/*
 *
 * Tag: Implementation
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
const int N = 110;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n;

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        printf("Case #%d: ",cas++);
        for (int i = 0; i < n; ++ i) {
            if (!i) {
                printf("Koko");
            } else {
                printf("koko");
            }
            if (i < n - 1) {
                printf(",");
            } else {
                printf(".");
            }
        }
        puts("");
    }
    return 0;
}
