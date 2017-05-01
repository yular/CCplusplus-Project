/*
*
* Tag: Data Structure (Fenwick Tree)
* Time: O(nlgn), Query: O(lgn)
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
const int N = 21000;
const int M = 10300;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, q, l, r;
long long arr[N], v, ans;

int lowbit(int x){
    return x&-x;
}

void update(int start, long long v){
    for (int i = start; i <= n; i += lowbit(i)) {
        arr[i] += v;
    }
}

long long calsum(int end){
    long long res = 0;
    for (int i = end; i > 0; i -= lowbit(i)) {
        res += arr[i];
    }
    return res;
}


int main(){
    memset(arr, 0, sizeof(arr));
    scanf("%d",&n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%lld",&v);
        update(i, v);
    }
    scanf("%d",&q);
    while (q --) {
        scanf("%d%d",&l,&r);
        ans = calsum(r);
        ans -= calsum(l - 1);
        printf("%lld\n",ans);
    }
    return 0;
}
