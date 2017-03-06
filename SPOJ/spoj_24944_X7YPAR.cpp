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
const int N = 10002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int v;

int main(){
    int cnt_divsvn = 0, cnt_even = 0;
    while (scanf("%d",&v) && v != 0) {
        if (v%7 == 0)
            ++ cnt_divsvn;
        if (v%2 == 0)
            ++ cnt_even;
    }
    printf("%d %d\n",cnt_divsvn,cnt_even);
    return 0;
}
