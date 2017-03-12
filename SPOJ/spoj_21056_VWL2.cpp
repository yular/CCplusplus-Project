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
char nm[M];
int vcnt, len;

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        vcnt = 0;
        scanf("%s",nm);
        for (int i = 0; nm[i]; ++ i) {
            if (nm[i] == 'a' || nm[i] == 'e' || nm[i] == 'i' || nm[i] == 'o' || nm[i] == 'u') {
                ++ vcnt;
            }
        }
        puts(nm);
        len = strlen(nm);
        if (vcnt > len - vcnt) {
            puts("1");
        } else {
            puts("0");
        }
    }
    return 0;
}
