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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 1000100;
const int M = 3000;
const long long MOD = 1000000007;
const double eps = 1e-10;
const double pi = acos(-1.0);
struct node {
    int val, pos;
}arr[N];
int btree[N];
int ans, n, v;

int lowbit(int x){
    return x&-x;
}

bool cmp(const node &a, const node &b){
    return a.val > b.val;
}

void update(int pos){
    for (int i = pos; i <= n; i += lowbit(i)) {
        ++ btree[i];
    }
}

int getsum(int pos){
    int res = 0;
    for (int i = pos; i > 0; i -= lowbit(i)) {
        res += btree[i];
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        ans = 0;
        memset(btree, 0 , sizeof(btree));
        scanf("%d",&n);
        for (int i = 1; i <= n; ++ i) {
            scanf("%d",&arr[i].val);
            arr[i].pos = i;
        }
        sort(arr + 1, arr + n + 1, cmp);
        for (int i = 1; i <= n; ++ i) {
            v = getsum(arr[i].pos);
            if (arr[i].pos - v != arr[i].val) {
                ++ ans;
                update(arr[i].pos);
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
