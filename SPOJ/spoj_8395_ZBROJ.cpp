/*
*
* Tag: Greedy
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
int min_a, min_b, max_a, max_b;
char a[N], b[N];

int main(){
    scanf("%s%s",a,b);
    min_a = min_b = max_a = max_b = 0;
    for (int i = 0; a[i]; ++ i) {
        if (a[i] != '5' && a[i] != '6') {
            min_a = min_a*10 + (a[i] - '0');
            max_a = max_a*10 + (a[i] - '0');
        } else {
            min_a = min_a*10 + 5;
            max_a = max_a*10 + 6;
        }
    }
    for (int i = 0; b[i]; ++ i) {
        if (b[i] != '5' && b[i] != '6') {
            min_b = min_b*10 + (b[i] - '0');
            max_b = max_b*10 + (b[i] - '0');
        } else {
            min_b = min_b*10 + 5;
            max_b = max_b*10 + 6;
        }
    }
    printf("%d %d\n",min_a + min_b, max_a + max_b);
    return 0;
}
