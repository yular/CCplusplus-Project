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
const int N = 100020;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
unordered_map<string, int> dict;
unordered_set<string> st;
int n;

void init(){
    dict.clear();
    st.clear();
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        init();
        for (int i = 0; i < n; ++ i) {
            string s;
            cin>>s;
            if (dict.find(s) == dict.end()) {
                dict[s] = 0;
            }
            ++ dict[s];
            if (dict[s] == 1) {
                st.insert(s);
            } else {
                st.erase(s);
            }
        }
        int ans = st.size();
        printf("%d\n",ans);
    }
    return 0;
}
