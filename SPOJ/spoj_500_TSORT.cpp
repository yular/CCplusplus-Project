/*
 *
 * Tag: Sort
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
const int N = 1050000;
const int M = 20;
const double eps = 1e-10;
int n;
int arr[N];

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&arr[i]);
    }
    sort(arr, arr + n);
    bool isfirst = true;
    for (int i = 0; i < n; ++ i) {
        if (!isfirst) {
            printf(" ");
        }
        printf("%d",arr[i]);
        isfirst = false;
    }
    puts("");
    return 0;
}
