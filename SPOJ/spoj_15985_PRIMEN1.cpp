/*
*
* Tag: Implementation
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
const int N = 2100002;
const int M = 100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
char wd[N];
int wcnt[M];

int main(){
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        scanf("%s",wd);
        memset(wcnt, 0, sizeof(wcnt));
        for (int i = 0; wd[i]; ++ i ) {
            ++ wcnt[wd[i] - 'A'];
        }
        bool isPalind = true;
        int oddcnt = 0;
        for (int i = 0; i < 26; ++ i) {
            if (wcnt[i]%2 == 1) {
                ++ oddcnt;
            }
        }
        if (oddcnt > 1) {
            printf("Case %d: NO\n",cas);
        } else {
            printf("Case %d: YES\n",cas);
        }
    }
    return 0;
}
