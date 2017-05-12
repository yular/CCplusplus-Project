/*
*
* Tag: Greedy
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
const int N = 530000;
const int M = 2150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, cnt, ans[M];
pair<int, int> hero[M];

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}

int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d",&hero[i].first);
        hero[i].second = i;
    }
    sort(hero + 1, hero + n + 1, cmp);
    hero[n + 1].first = INT_MAX;
    cnt = 0;
    for (int i = 1; i <= n; ++ i) {
        if (i >= hero[i].first && i + 1 < hero[i + 1].first) {
            ans[++ cnt] = i;
        }
    }
    printf("%d\n",cnt);
    for (int i = 1; i <= cnt; ++ i) {
        printf("%d",ans[i]);
        for (int j = 1; j <= ans[i]; ++ j) {
            printf(" %d",hero[j].second);
        }
        puts("");
    }
    return 0;
}
