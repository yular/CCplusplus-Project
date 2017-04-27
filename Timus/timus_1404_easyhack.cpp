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
const int N = 120;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
char s[N], t[N];

int main(){
    scanf("%s",&s);
    memset(t, 0, sizeof(t));
    int v = 0, u = 0;
    for (int i = 0; s[i]; ++ i) {
        v = s[i] - 'a';
        if (i == 0) {
            v = (v + 21)%26;
        } else {
            u = s[i - 1] - 'a';
            v = (v - u + 26)%26;
        }
        t[i] = (v + 'a');
    }
    puts(t);
    return 0;
}
