/*
 *
 * Tag: Implementation
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
const int N = 10000300;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
int n;
int ans;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        if (!n) {
            printf("1\n0\n");
        } else if (n%2 == 1){
            printf("%d\n%d\n",n/2+1,n/2);
        } else {
            printf("%d\n%d\n",n/2,n/2);
        }
    }
    return 0;
}
