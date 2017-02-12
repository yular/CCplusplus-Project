/*
*
* Tag: Greedy
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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 300;
const int M = 50000;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
int n, k, s, sum, cnt, v;
priority_queue<int> pq;

int main(){
    scanf("%d%d%d",&n,&k,&s);
    sum = k*s;
    cnt = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        pq.push(v);
    }
    while (!pq.empty() && sum > 0) {
        sum -= pq.top();
        pq.pop();
        ++ cnt;
    }
    printf("%d\n",cnt);
    return 0;
}
 
