/*
 *
 * Tag: Sort
 * Time: O(nlgn)
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
const int N = 1100;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n, k;
int a[N], b[N];

bool cmp(const int &a, const int &b){
    return b < a;
}

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&k);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&a[i]);
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&b[i]);
        }
        sort(a, a + n);
        sort(b, b + n, cmp);
        bool isright = true;
        for (int i = 0; i < n; ++ i) {
            if (a[i] + b[i] < k) {
                isright = false;
                break;
            }
        }
        if (isright) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
