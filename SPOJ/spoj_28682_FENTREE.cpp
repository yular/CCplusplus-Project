/*
*
* Tag: Data Structure
* Time: O(nlgn)
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
const int N = 2000200;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, u, v, q;
long long btree[N], sum, a;
char op[M];

int lowbit(int x){
    return x&-x;
}

void updateBTree(int l, long long v){
    for (int i = l; i <= n; i += lowbit(i)) {
        btree[i] += v;
    }
}

long long sumBTree(int r){
    long long res = 0;
    for (int i = min(r, n); i > 0; i -= lowbit(i)) {
        res += btree[i];
    }
    return res;
}

int main(){
    memset(btree, 0, sizeof(btree));
    scanf("%d",&n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%lld",&a);
        updateBTree(i,a);
    }
    scanf("%d",&q);
    while (q --) {
        scanf("%s%d%d",op,&u,&v);
        if (op[0] == 'u') {
            updateBTree(u,v);
        } else {
            sum = sumBTree(v) - sumBTree(u - 1);
            printf("%lld\n",sum);
        }
    }
    return 0;
}
