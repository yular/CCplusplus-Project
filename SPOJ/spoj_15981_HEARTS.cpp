/*
 *
 * Tag: Geometry
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
const int N = 1030003;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
int n;
pair<int, int> p[2];

int main() {
    while(scanf("%d%d%d%d",&p[0].first,&p[0].second,&p[1].first,&p[1].second) == 4){
        if (p[1].second < p[0].first || p[0].second < p[1].first) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
