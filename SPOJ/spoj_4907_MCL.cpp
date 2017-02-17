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
const int N = 30;
const int M = 100;
const int NN = 1010;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
string str;
int cnt[N], v, ans, maxcnt;

int main(){
    while (getline(cin, str)) {
        memset(cnt, 0, sizeof(cnt));
        maxcnt = 0;
        ans = 27;
        for (int i = 0; i < str.size(); ++ i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                ++ cnt[str[i] - 'A'];
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                ++ cnt[str[i] - 'a'];
            }
        }
        for (int i = 0; i < 26; ++ i) {
            if (cnt[i] > maxcnt) {
                maxcnt = cnt[i];
                ans = i;
            }
        }
        printf("%c %d\n",('A' + ans),maxcnt);
    }
    return 0;
}
