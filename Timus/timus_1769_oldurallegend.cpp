/*
*
* Tag: Search
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
const int N = 1000100;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
bool vis[N];
char str[N];

int main(){
    scanf("%s",str);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; str[i]; ++ i) {
        int v = 0;
        for (int j = 1; j <= 6 && str[i + j - 1]; ++ j) {
            v = v*10 + (str[i + j - 1] - '0');
            vis[v] = 1;
        }
    }
    for (int i = 1; i < N; ++ i) {
        if (!vis[i]) {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
