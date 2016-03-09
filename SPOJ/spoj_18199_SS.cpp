/*
 *
 * Tag: Implementation
 * Time: O(n)
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
const int N = 100010;
const int M = 30;
const long long MOD = 1000000007;
const double eps = 1e-10;
char s[M], t[M];

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s%s",s,t);
        int sums = 0, sumt = 0;
        for (int i = 0; s[i]; ++ i) {
            if (s[i] == '6') {
                s[i] = '5';
            }
            sums *= 10;
            sums += (s[i] - '0');
        }
        for (int i = 0; t[i]; ++ i) {
            if (t[i] == '6') {
                t[i] = '5';
            }
            sumt *= 10;
            sumt += (t[i] - '0');
        }
        printf("%d ",sums + sumt);
        sums = sumt = 0;
        for (int i = 0; s[i]; ++ i) {
            if (s[i] == '5') {
                s[i] = '6';
            }
            sums *= 10;
            sums += (s[i] - '0');
        }
        for (int i = 0; t[i]; ++ i) {
            if (t[i] == '5') {
                t[i] = '6';
            }
            sumt *= 10;
            sumt += (t[i] - '0');
        }
        printf("%d\n",sums + sumt);
    }
    return 0;
}
