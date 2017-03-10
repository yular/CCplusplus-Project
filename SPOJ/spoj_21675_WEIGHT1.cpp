/*
*
* Tag: DFS
* Time: O(2^n)
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
#include <map>
#include <set>
using namespace std;
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, w, arr[M], ans;

void dfs(int sum, int sta){
    if (sum >= w) {
        ans = min(ans, sum - w);
        return ;
    }
    for (int i = sta + 1; i < n; ++ i) {
        if (sum + arr[i] - w >= ans)
            continue;
        dfs(sum + arr[i], i);
        if(ans == 0)
            return ;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&w);
        ans = INT_MAX;
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&arr[i]);
        }
        sort(arr, arr + n);
        for (int i = 0; i < n; ++ i) {
            dfs(arr[i], i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
