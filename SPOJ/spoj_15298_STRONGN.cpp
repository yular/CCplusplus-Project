/*
 *
 * Tag: Math
 * Time: O(lgn)
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
const int N = 1000300;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
long long fact[M];
long long n;

void init(){
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 10; ++ i) {
        fact[i] = fact[i - 1]*i;
    }
}

bool check(){
    if (!n) {
        return false;
    }
    long long res = 0;
    long long m = n;
    while (m) {
        res += fact[m%10];
        m /= 10;
    }
    return res == n;
}

int main() {
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld",&n);
        if (check()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
