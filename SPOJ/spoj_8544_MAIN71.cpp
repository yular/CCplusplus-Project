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
const int N = 1002000;
const int M = 120;
const double eps = 1e-10;
char dict[M], s[N], t[N];
int order[M];

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        memset(order, 0, sizeof(order));
        scanf("%s%s%s",dict,s,t);
        for (int i = 0; dict[i]; ++ i) {
            order[dict[i]-'a'] = i;
        }
        int res = 0;
        for (int i = 0; s[i]; ++ i) {
            int uid = s[i] - 'a', vid = t[i] - 'a';
            if (order[uid] > order[vid]) {
                res = 1;
                break;
            } else if (order[uid] < order[vid]) {
                res = -1;
                break;
            }
        }
        if (!res) {
            puts("=");
        } else if (res > 0) {
            puts(">");
        } else {
            puts("<");
        }
    }
    return 0;
}
