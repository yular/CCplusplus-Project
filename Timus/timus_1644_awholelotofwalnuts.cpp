/*
*
* Tag: Implementation
* Time: O(1)
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
const int N = 200;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int state[N], n, v;
char s[M];

int main(){
    scanf("%d",&n);
    memset(state, 0, sizeof(state));
    state[0] = state[1] = state[2] = 1;
    state[10] = 2;
    for (int i = 0; i < n; ++ i) {
        scanf("%d%s",&v,s);
        if (s[0] == 'h') {
            state[v] |= 1;
        } else {
            state[v] |= 2;
        }
    }
    bool isconsit = true;
    int ans = 10;
    for (int i = 3; i < 10; ++ i) {
        if (state[i] == 3) {
            isconsit = false;
            break;
        } else if (state[i] == 2) {
            ans = min(ans, i);
        } else if (state[i] == 1 && ans < 10){
            isconsit = false;
            break;
        }
    }
    if (isconsit) {
        printf("%d\n",ans);
    } else {
        puts("Inconsistent");
    }
    return 0;
}
