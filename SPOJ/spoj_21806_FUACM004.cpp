/*
 *
 * Tag: Implementation
 * Time: O(n^2)
 * Space: O(n)
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
int n,k;
int a[M], maxa[M], mina[M];

int main() {
    scanf("%d%d",&n,&k);
    int cnt = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = i + 1; j < n; ++ j) {
            if (max(a[i], a[j]) - min(a[i], a[j]) == k) {
                ++ cnt;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
