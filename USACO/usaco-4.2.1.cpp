/*
 *
 * Tag: Graph Theory (Max Flow)
 * Time: O(V*E^2)
 * Space: O(V^2)
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <queue>
using namespace std;
const int N = 205;
int s, t, n, m;
long long mp[N][N], ans, pre[N], delta[N];

bool bfs(){
    queue<int> q;
    memset(pre, 0, sizeof(pre));
    memset(delta, 0, sizeof(delta));
    
    delta[s] = LLONG_MAX;
    q.push(s);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 1; i <= m; ++ i) {
            if (delta[i] == 0 && mp[cur][i] > 0) {
                delta[i] = min(delta[cur], mp[cur][i]);
                pre[i] = cur;
                q.push(i);
            }
        }
    }
    
    return delta[t]!=0;
}

void edmkp(){
    while (bfs()) {
        for (int i = t; i != s; i = pre[i]) {
            mp[pre[i]][i] -= delta[t];
            mp[i][pre[i]] += delta[t];
        }
        ans += delta[t];
    }
}

int main(){
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    memset(mp, 0, sizeof(mp));
    scanf("%d%d",&n,&m);
    ans = 0;
    s = 1; t = m;
    for(int i = 0; i < n; ++ i){
        int u, v, c;
        scanf("%d%d%d",&u,&v,&c);
        mp[u][v] += c;
    }
    edmkp();
    printf("%d\n", ans);
    return 0;
}
