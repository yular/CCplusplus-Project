/*
 *
 * Tag: Implementation
 * Time: O(n^2)
 * Space: O(1)
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
const int N = 1033;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
int n;

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        for (int j = i; j < n; ++ j) {
            char v = 'A' + j;
            printf("%c",v);
        }
        puts("");
    }
    return 0;
}
