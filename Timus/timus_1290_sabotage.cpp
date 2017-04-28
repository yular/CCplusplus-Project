/*
*
* Tag: Implementation
* Time: O(nlgn)
* Space: O(lgn)
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
const int N = 50200;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, m, arr[N], ans[N];

int main(){
    scanf("%d",&n);
    m = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&arr[i]);
    }
    sort(arr, arr + n);
    for (int i = n - 1; i >= 0; -- i) {
        printf("%d\n",arr[i]);
    }
    return 0;
}
