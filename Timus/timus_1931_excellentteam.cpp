/*
*
* Tag: Implementation
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
int n, v, arr[N], cur, ans, anscnt;

int main(){
    scanf("%d",&n);
    anscnt = -1;
    int tmpans = 1000000007,cnt = -1,idx = 1;
    for (int i=1;i<=n;i++){
        scanf("%d",&v);
        cnt++;
        if (v < tmpans){
            if (cnt >= anscnt){
                ans = idx;
                anscnt = cnt;
            }
            cnt = 0;
            tmpans = v;
            idx = i;
        }
    }
    if (cnt >= anscnt){
        ans = idx;
        anscnt = cnt;
    }
    printf("%d\n",ans);
    return 0;
}
