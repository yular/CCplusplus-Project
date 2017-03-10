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
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
char s[N], t[N];

int main(){
    int T;
    scanf("%d",&T);
    while(T --) {
        scanf("%s",s);
        memset(t, 0, sizeof(t));
        for (int i = 0; s[i]; ++ i) {
            s[i] = ((s[i] - 'a' + 25)%26 + 'a');
        }
        int n = strlen(s);
        int m = n/3;
        for (int i = 0, j = n - m, k = 0; k < n; ++ k) {
            if (k%3 == 2) {
                t[k] = s[j ++];
            } else {
                t[k] = s[i ++];
            }
        }
        int i = 0, j = n - 1;
        while (i < j) {
            swap(t[i], t[j]);
            ++ i;
            -- j;
        }
        puts(t);
    }
    return 0;
}
