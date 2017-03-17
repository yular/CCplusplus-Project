/*
*
* Tag: Data Structure (Hash)
* Time: O(n!)
* Space: O(n!)
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
const int N = 2100002;
const int M = 2100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int fact[M], n, v;
unordered_set<int> tmpst, st;

void init(){
    fact[0] = 1;
    for (int i = 1; i <= 10; ++ i) {
        fact[i] = fact[i - 1]*i;
    }
    st.clear();
    tmpst.clear();
    st.insert(1);
    unordered_set<int>::iterator it;
    for (int i = 1; i <= 10; ++ i) {
        tmpst = st;
        for (it = st.begin(); it != st.end(); ++ it) {
            tmpst.insert(*it + fact[i]);
        }
        tmpst.insert(fact[i]);
        st = tmpst;
    }
}



int main(){
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&v);
        if (st.find(v) != st.end()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
