/*
 *
 * Tag: Math
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
const int N = 200;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
int n;

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        n %= 1440;
        int h = 9, m = 0;
        h += (n/60);
        m += (n%60);
        h %= 24;
        m %= 60;
        char ansh[3] = {0}, ansm[3] = {0};
        if (h < 10) {
            ansh[0] = '0';
            ansh[1] = ('0' + h);
        } else {
            ansh[0] = (h/10 + '0');
            ansh[1] = (h%10 + '0');
        }
        if (m < 10) {
            ansm[0] = '0';
            ansm[1] = ('0' + m);
        } else {
            ansm[0] = (m/10 + '0');
            ansm[1] = (m%10 + '0');
        }
        printf("Scenario #%d: %s:%s\n",cas++, ansh,ansm);
    }
    return 0;
}
