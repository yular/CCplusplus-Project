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
const int N = 2000011;
const int M = 1010;
const long long MOD = 1000000007;
const double eps = 1e-10;
char s[N], t[N];
int id;

void reversestr(int sta, int ends){
    for (int i = ends; i >= sta; -- i) {
        t[id ++] = s[i];
    }
}

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        id = 0;
        scanf("%s",s);
        memset(t, 0, sizeof(t));
        for (int i = 0; s[i]; ++ i) {
            if (s[i] == '[') {
                int sta = i + 1, ends = i + 1;
                while (s[i] != ']') {
                    ++ i;
                }
                ends = i - 1;
                reversestr(sta, ends);
            } else {
                t[id ++] = s[i];
            }
        }
        puts(t);
    }
    return 0;
}
