/*
 *
 * Tag: Heap
 * Time: O(n*k^3*lgk)
 * Space: O(k^3)
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
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
priority_queue<int, vector<int>, greater<int> > pq;
int tmparr[N];
int n;

int main() {
    while (scanf("%d",&n) == 1) {
        while (!pq.empty()) {
            pq.pop();
        }
        pq.push(1);
        pq.push(2);
        pq.push(3);
        for (int i = 1; i < n; ++ i) {
            int len = 0;
            while (!pq.empty()) {
                int cur = pq.top();
                pq.pop();
                tmparr[len ++] = cur*10 + 1;
                tmparr[len ++] = cur*10 + 2;
                tmparr[len ++] = cur*10 + 3;
            }
            for (int j = 0; j < len; ++ j) {
                pq.push(tmparr[j]);
            }
        }
        while (!pq.empty()) {
            printf("%d\n",pq.top());
            pq.pop();
        }
        puts("");
    }
    return 0;
}
