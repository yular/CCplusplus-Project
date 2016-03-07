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
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
unordered_set<int> st;
int n, x;

int main() {
    int T, cas = 1;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        st.clear();
        for (int i = 0; i < n; ++ i) {
            int v;
            scanf("%d",&v);
            st.insert(v);
        }
        scanf("%d",&x);
        if (st.find(x) != st.end()) {
            printf("Case %d: YES\n",cas++);
        } else {
            printf("Case %d: NO\n",cas++);
        }
    }
    return 0;
}
