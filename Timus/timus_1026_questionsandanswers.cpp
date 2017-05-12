/*
*
* Tag: Data Structure
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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 530000;
const int M = 150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, q, v, arr[N];
char s[M];

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&arr[i]);
    }
    scanf("%s",s);
    sort(arr, arr + n);
    scanf("%d",&q);
    while (q --) {
        scanf("%d",&v);
        printf("%d\n",arr[v - 1]);
    }
    return 0;
}
