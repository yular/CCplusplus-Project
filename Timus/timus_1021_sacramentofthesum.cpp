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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 53000;
const int M = 50;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, m, v;
unordered_set<int> st;

int main(){
    scanf("%d",&n);
    st.clear();
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        st.insert(v);
    }
    scanf("%d",&m);
    bool isfind = false;
    for (int i = 0; i < m; ++ i) {
        scanf("%d",&v);
        if (st.count(10000 - v) > 0) {
            isfind = true;
            break;
        }
    }
    if (isfind) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
