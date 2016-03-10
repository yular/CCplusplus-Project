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
const int N = 100010;
const int M = 130;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n;
int ans[M], bnd;
unordered_set<int> st;

int main() {
    scanf("%d",&n);
    bnd = 0;
    for (int i = 0; i < n; ++ i) {
        int v;
        scanf("%d",&v);
        if (st.find(v) == st.end()) {
            st.insert(v);
            ans[bnd ++] = v;
        }
    }
    bool isfirst = true;
    for (int i = 0; i < bnd; ++ i) {
        if (!isfirst) {
            printf(" ");
        }
        printf("%d",ans[i]);
        isfirst = false;
    }
    puts("");
    isfirst = true;
    for (int i = bnd - 1; i >= 0; -- i) {
        if (!isfirst) {
            printf(" ");
        }
        printf("%d",ans[i]);
        isfirst = false;
    }
    puts("");
    return 0;
}
