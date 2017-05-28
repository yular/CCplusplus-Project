/*
*
* Tag: Data Structure/Graph
* Time: O(n)
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
const int N = 1020;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int cnt[N], parent[N], deg[N];
int n;

void init(){
    for (int i = 1; i < N; ++ i) {
        parent[i] = i;
        deg[i] = 0;
        cnt[i] = 0;
    }
    n = 0;
}

int find(int x){
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionedge(int u, int v){
    u = find(u), v = find(v);
    if (u == v) {
        return ;
    }
    parent[v] = u;
}

int main(){
    int u, v;
    init();
    while (scanf("%d%d",&u,&v) == 2) {
        unionedge(u, v);
        ++ deg[u];
        ++ deg[v];
        n = max(n, max(u, v));
    }
    bool isfind = true;
    for (int i = 1; i <= n; ++ i) {
        cnt[find(i)] += deg[i];
    }
    for (int i = 1; i <= n; ++ i) {
        if (cnt[find(i)]%4 != 0) {
            isfind = false;
            break;
        }
    }
    if (isfind) {
        puts("1");
    } else {
        puts("0");
    }
    return 0;
}
