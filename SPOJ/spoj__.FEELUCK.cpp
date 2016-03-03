/*
 *
 * Tag: Sort
 * Time: O(nlgn) or O(1)
 * Space: O(nlgn) or O(1)
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
const int N = 20;
const int M = 130;
const double eps = 1e-10;
struct weblink{
    char link[M];
    int id, relvant;
    bool operator < (const weblink a) const {
        if (relvant == a.relvant)
            return id < a.id;
        return a.relvant < relvant;
    }
}g[N];

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        for (int i = 0; i < 10; ++ i) {
            scanf("%s%d",g[i].link,&g[i].relvant);
            g[i].id = i;
        }
        sort(g, g + 10);
        printf("Case #%d:\n",cas ++);
        puts(g[0].link);
        for (int i = 1; i < 10; ++ i) {
            if (g[i].relvant == g[0].relvant) {
                puts(g[i].link);
            } else {
                break;
            }
        }
    }
    return 0;
}
