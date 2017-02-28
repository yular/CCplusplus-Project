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
const int N = 200200;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
char s[M];

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",s);
        for (int i = 0; s[i]; ++ i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            } else {
                s[i] -= 32;
            }
        }
        puts(s);
    }
    return 0;
}
