/*
 *
 * Tag: Graph (DFS)
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 1010;
const int M = 10310;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n;
struct node{
    int u, v, type;
    int nxt;
}e[M];
int head[N], num;
bool vis[N];
char inp[20];
int s;

void init(){
    num = 0;
    for (int i = 0; i < N; ++ i) {
        head[i] = -1;
        vis[i] = 0;
    }
}

void addedge(int u, int v, int type){
    e[num].u = u;
    e[num].v = v;
    e[num].type = type;
    e[num].nxt = head[u];
    head[u] = num ++;
}

int getInt(){
    int res = 0;
    for (int i = 0; inp[i]; ++ i) {
        res *= 10;
        res += (inp[i] - '0');
    }
    return res;
}

void dfs(int u, int type){
 //   printf("u = %d, type = %d\n",u,type);
    for (int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if (!vis[v] && e[i].type == type) {
            vis[v] = 1;
            -- n;
            dfs(v, type);
        }
    }
}


int main() {
    freopen("/Users/ybc/Project/CCPP/ACM/input.txt", "r", stdin);
    init();
    int m;
    scanf("%d",&n);
    m = n;
    while (scanf("%s",inp)) {
        if (strcmp(inp, "BLOOD") == 0) {
            break;
        }
        int u = getInt(), v;
        scanf("%d",&v);
     //   printf("%d %d\n",u,v);
        addedge(u, v, 0);
        addedge(v, u, 1);
    }
    while (scanf("%d",&s) == 1) {
        if (!vis[s]) {
            -- n;
        }
        vis[s] = 1;
        dfs(s, 0);
        dfs(s, 1);
    }
    if (!n) {
        puts("0");
    } else {
        bool isfirst = true;
        for (int i = 1; i <= m; ++ i) {
            if (!vis[i]) {
                if (!isfirst) {
                    printf(" ");
                }
                printf("%d",i);
                isfirst = false;
            }
        }
        puts("");
    }
    return 0;
}
