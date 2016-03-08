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
const int N = 1033;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
char s[N];
int n;

int main() {
    int T;
    scanf("%d",&T);
    while( T --){
        scanf("%s",s);
        scanf("%d",&n);
        for (int i = 0; s[i]; ++ i) {
            char v = 0;
            if (s[i] >= 'A' && s[i] <= 'Z') {
                v = (s[i] - 'A' + n)%26 + 'A';
            } else {
                v = (s[i] - 'a' + n)%26 + 'a';
            }
            printf("%c",v);
        }
        puts("");
    }
    return 0;
}
