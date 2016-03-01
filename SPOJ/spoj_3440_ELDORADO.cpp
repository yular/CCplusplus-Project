/*
 *
 * Tag: Math
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
const int N = 15000;
const int M = 120;
const double eps = 1e-10;
int a, b;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&a,&b);
        printf("%d\n",a*b);
    }
    return 0;
}
