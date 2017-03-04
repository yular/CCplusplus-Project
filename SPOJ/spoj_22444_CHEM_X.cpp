/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
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
const int N = 2020002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
char s[M];
bool vis[M];

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",s);
        memset(vis, 0, sizeof(vis));
        for (int i = 0; s[i]; ++ i) {
            vis[s[i] - 'a'] = 1;
        }
        for (int i = 0; i < 26; ++ i) {
            if (vis[i]) {
                printf("%c",(char)('a' + i));
            }
        }
        puts("");
    }
    return 0;
}
