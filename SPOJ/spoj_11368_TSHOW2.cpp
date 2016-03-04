/*
 *
 * Tag: Hash && Math
 * Time: O(1)
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
const int N = 120;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
int dict[N];
int n;

void init(){
    dict[0] = 0;
    dict[1] = 1;
    for (int i = 2; i < 60; ++ i) {
        dict[i] = (dict[i - 1] + dict[i - 2])%10;
    }
}

int main() {
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        -- n;
        printf("%d\n",dict[n%60]);
    }
    return 0;
}
