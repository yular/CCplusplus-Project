/*
*
* Tag: Implementation
* Time: O(nm)
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
const int N = 300;
const int M = 50000;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
char mp[N][N];
int n, m, cnt;
map<int, int> dict;

int main(){
    scanf("%d%d",&n,&m);
    dict.clear();
    for (int i = 0; i < n; ++ i )
        scanf("%s",mp[i]);
    for (int i = 0; i < m; ++ i ) {
        cnt = 0;
        for (int j = 0; j < n; ++ j) {
            if (mp[j][i] == '1') {
                if (cnt > 0) {
                    ++ dict[cnt];
                }
                cnt = 0;
            } else {
                ++ cnt;
            }
        }
        if (cnt > 0) {
            ++ dict[cnt];
        }
    }
    map<int,int>::iterator it = dict.begin();
    for (; it != dict.end(); ++ it) {
        printf("%d %d\n",it->first, it->second);
    }
    return 0;
}
