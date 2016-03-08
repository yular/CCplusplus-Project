/*
 *
 * Tag: Sort && Hash
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 103000;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
int n, k;
int arr[N];
unordered_set<int> st;

int main() {
    while(scanf("%d%d",&n,&k) == 2){
        st.clear();
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&arr[i]);
            st.insert(arr[i]);
        }
        int cnt = 0;
        sort(arr, arr + n);
        for (int i = 0; i < n; ++ i) {
            if (st.find(arr[i] + k) != st.end()) {
                ++ cnt;
            }
        }
        if (!k) {
            cnt = 0;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
