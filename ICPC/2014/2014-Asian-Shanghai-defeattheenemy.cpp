/*
*
* Tag: Greedy
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
const int N = 200200;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
struct node{
    int a, d, id;
}s1[N], s2[N];
int n, m, ans;
multiset<int> st;
multiset<int>::iterator it;

bool cmp(node x, node y){
    return x.a > y.a;
}

void cal(){
    st.clear();
    for (int i = 0, j = 0; j < m; ++ j) {
        while (s2[j].a <= s1[i].a && i < n) {
            st.insert(s1[i].d);
            ++ i;
        }
        if (st.empty()) {
            ans = -1;
            return ;
        }
        it = st.upper_bound(s2[j].d);
        if (it == st.end()) {
            st.erase(st.begin());
            -- ans;
        } else
            st.erase(it);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; ++ cas) {
        ans = 0;
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d",&s1[i].a,&s1[i].d);
            s1[i].id = 0;
        }
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d",&s2[i].d,&s2[i].a);
            s2[i].id = 1;
        }
        sort(s1, s1 + n, cmp);
        sort(s2, s2 + m, cmp);
        ans = n;
        cal();
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
