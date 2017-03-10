/*
*
* Tag: Data Structure
* Time: O(nlgn)
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
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, l ,r, q, x, v;
set<int> st;
set<int>::iterator it;

int main(){
    st.clear();
    scanf("%d%d%d%d",&n,&l,&r,&q);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        if (i >= l && i <= r)
            st.insert(v);
    }
    for (int i = 0; i < q; ++ i) {
        scanf("%d",&x);
        it = st.upper_bound(x);
        if (it == st.end()) {
            puts("-1");
        } else {
            printf("%d\n",*it);
        }
    }
    return 0;
}
