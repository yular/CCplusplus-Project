/*
 *
 * Tag: Number Theory
 * Time: ?
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
const int N = 100020;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
int n;
long long sum;

bool check(){
    for (int i = 2; i <= sqrt(sum); ++ i) {
        if (sum%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        sum = 0;
        for (int i = 0; i < n; ++ i) {
            long long v;
            scanf("%lld",&v);
            sum += v;
        }
        if (check()) {
            puts("I LOVE MILD");
        } else {
            puts("GIVE ME MOMENTS");
        }
    }
    return 0;
}
