/*
*
* Tag: Data Structure (Hash)
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
const int N = 2100002;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, m, v;
unordered_map<int, int> dict;

int main(){
    dict.clear();
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        ++ dict[v];
    }
    scanf("%d",&m);
    while (m --) {
        scanf("%d",&v);
        if (dict.find(v) != dict.end() && dict[v] > 0) {
            puts("YES");
            -- dict[v];
        } else {
            puts("NO");
        }
    }
    return 0;
}
