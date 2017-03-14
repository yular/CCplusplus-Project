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
const int N = 210002;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, a[M], uniqcnt;
char s[M];

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%s",s);
        memset(a, 0, sizeof(a));
        uniqcnt = 0;
        for (int j = 0; s[j]; ++ j) {
            ++ a[s[j] - 'a'];
        }
        for (int j = 0; j < 26; ++ j) {
            if (a[j] == 1) {
                ++ uniqcnt;
            }
        }
        if (uniqcnt == 0) {
            puts("-1");
        } else {
            for (int j = 0; j < 26; ++ j) {
                if (a[j] == 1) {
                    printf("%c",(char)('a' + j));
                }
            }
            puts("");
        }
    }
    return 0;
}
