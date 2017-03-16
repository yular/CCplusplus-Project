/*
*
* Tag: Sort
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
#include <map>
#include <set>
using namespace std;
const int N = 2100002;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, k, arr[N];

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&arr[i]);
        }
        sort(arr, arr + n);
        scanf("%d",&k);
        printf("%d\n",arr[n - k]);
    }
    return 0;
}
