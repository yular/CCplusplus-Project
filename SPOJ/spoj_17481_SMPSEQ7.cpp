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
const int N = 310;
const int M = 101010;
const double eps = 1e-10;
int n;
unordered_map<int, int> dict;
int v;

int main() {
    scanf("%d",&n);
    bool iscorrect = true;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        if (dict.find(v) == dict.end()) {
            dict[v] = 0;
        }
        ++ dict[v];
        if (dict[v] >= 3) {
            iscorrect = false;
        }
    }
    if (iscorrect) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
