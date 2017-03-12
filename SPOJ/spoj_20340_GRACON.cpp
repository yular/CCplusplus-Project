/*
*
* Tag: DFS
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
#include <map>
#include <set>
using namespace std;
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, m, u, v;
map<int, set<int> > g;
set<int> vis;

void dfs(int u){
    vis.insert(u);
    if (vis.size() == n) {
        return ;
    }
    set<int>::iterator it = g[u].begin();
    for (; it != g[u].end(); ++ it) {
        if (vis.find(*it) == vis.end()) {
            dfs(*it);
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
        g.clear();
        vis.clear();
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d",&u,&v);
            g[u].insert(v);
            g[v].insert(u);
        }
        dfs(u);
        if (vis.size() == n) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
