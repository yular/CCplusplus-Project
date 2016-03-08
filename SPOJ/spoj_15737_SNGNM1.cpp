/*
 *
 * Tag: Math
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
const int N = 1030;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
int n;
char s[N];

int main() {
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%s",s);
        n = 0;
        for (int i = 0; s[i]; ++ i) {
            n *= 10;
            n += (s[i] - '0');
        }
        bool isdiv = true;
        for (int i = 0; s[i]; ++ i) {
            int v = s[i] - '0';
            if (v && n%v != 0) {
                isdiv = false;
            }
        }
        if (!n || !isdiv) {
            puts("no");
        } else {
            puts("yes");
        }
    }
    return 0;
}
