/*
*
* Tag: Implementation
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
struct student{
    int t[3];
    bool operator < (const student &a) const{
        return t[0] < a.t[0];
    }
}st[M];
int n;

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < 3; ++ j) {
            scanf("%d",&st[i].t[j]);
        }
    }
    int ans = 0, curt = 0;
    sort(st, st + n);
    for (int i = 0; i < n; ++ i) {
        st[i].t[0] -= ans;
        if (curt < st[i].t[0]) {
            curt = st[i].t[0];
        }
        curt += st[i].t[1];
        if (curt > st[i].t[2]) {
            ans += (curt - st[i].t[2]);
            curt = st[i].t[2];
        }
    }
    printf("%d\n",ans);
    return 0;
}
