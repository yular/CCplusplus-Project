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
const int N = 1002000;
const int M = 30;
const double eps = 1e-10;
long long facthash[M];
int cnt[M];
char s[M];

void init(){
    facthash[0] = 0;
    facthash[1] = 1;
    for (int i = 2; i <= 15; ++ i) {
        facthash[i] = facthash[i - 1]*i;
    }
}

int main() {
    init();
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        printf("Case %d: ", cas ++);
        scanf("%s",s);
        memset(cnt, 0, sizeof(cnt));
        int len = strlen(s);
        for (int i = 0; s[i]; ++ i) {
            ++ cnt[s[i] - 'A'];
        }
        long long ans = facthash[len];
        for (int i = 0; i < M; ++ i) {
            if (cnt[i]) {
                ans /= facthash[cnt[i]];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
