/*
 *
 * Tag: Sort (Best: O(n))
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
const int N = 3000200;
const int M = 1030000;
const int MOD = 100;
const double eps = 1e-10;
int arr[N];
int n;

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&arr[i]);
    }
    sort(arr, arr + n);
    printf("%d\n",arr[n/2]);
    return 0;
}
