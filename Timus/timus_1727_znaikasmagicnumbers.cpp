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
const int N = 153000;
const int M = 150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int ans[N], n, cnt;

int calc(int v){
    int res = 0;
    while (v > 0) {
        res += v%10;
        v /= 10;
    }
    return res;
}

int main(){
    scanf("%d",&n);
    cnt = 0;
    for (int i = 99999; i > 0 && n > 0; -- i) {
        if (n < 10) {
            ans[cnt ++] = n;
            break;
        }
        int m = calc(i);
        if (m > n) {
            continue;
        }
        ans[cnt ++] = i;
        n -= m;
    }
    printf("%d\n",cnt);
    for (int i = 0; i < cnt; ++ i) {
        printf("%d ",ans[i]);
    }
    puts("");
    return 0;
}
