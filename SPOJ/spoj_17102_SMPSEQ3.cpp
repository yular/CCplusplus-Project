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
const int N = 310;
const int M = 101010;
const double eps = 1e-10;
int n, m;
int s[N];
unordered_set<int> q;

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&s[i]);
    }
    scanf("%d",&m);
    for (int i = 0; i < m; ++ i) {
        int v;
        scanf("%d",&v);
        q.insert(v);
    }
    bool isfirst = true;
    for (int i = 0; i < n; ++ i) {
        if (q.find(s[i]) == q.end()) {
            if (!isfirst) {
                printf(" ");
            }
            printf("%d", s[i]);
            isfirst = false;
        }
    }
    puts("");
    return 0;
}
