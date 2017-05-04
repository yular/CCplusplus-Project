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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 33000;
const int M = 103;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, m, arr[N];

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&arr[i]);
    }
    m = m%n;
    for (int i = 0; i < 10; ++i, m = (m + 1)%n) {
        printf("%d", arr[m]);
    }
    puts("");
    return 0;
}
