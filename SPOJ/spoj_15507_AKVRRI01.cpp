/*
 *
 * Tag: Heap
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
const int N = 2000011;
const int M = 1010;
const long long MOD = 1000000007;
const double eps = 1e-10;
priority_queue<int> pq;
int n;

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        int v;
        scanf("%d",&v);
        pq.push(v);
    }
    bool isfirst = true;
    for (int i = 0; i < 3; ++ i) {
        if (!isfirst) {
            printf(" ");
        }
        printf("%d",pq.top());
        pq.pop();
        isfirst = false;
    }
    puts("");
    return 0;
}
