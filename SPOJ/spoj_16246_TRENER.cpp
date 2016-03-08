/*
 *
 * Tag: Hash
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
const int N = 103;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
int n;
int cnt[M];
char s[N];

int main() {
    while(scanf("%d",&n) == 1){
        bool hasres = false;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++ i) {
            scanf("%s",s);
            int id = s[0] - 'a';
            ++ cnt[id];
            if (cnt[id] >= 5) {
                hasres = true;
            }
        }
        if (!hasres) {
            puts("PREDAJA");
        } else {
            for (int i = 0; i < 26; ++ i) {
                if (cnt[i] >= 5) {
                    char v = 'a' + i;
                    printf("%c",v);
                }
            }
            puts("");
        }
    }
    return 0;
}
