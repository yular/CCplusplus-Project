/*
*
* Tag: Math
* Time: O(n)
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
const int N = 1530000;
const int M = 2150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, arr[M];

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&arr[i]);
    }
    sort(arr, arr + n);
    if (arr[0] > 1) {
        puts("1");
    } else if (arr[1] > 2) {
        puts("2");
    } else {
        int ans = 0;
        for (int i = 0; i < n; ++ i) {
            if (arr[i] > ans + 1) {
                break;
            }
            ans += arr[i];
        }
        printf("%d\n",ans + 1);
    }
    return 0;
}
