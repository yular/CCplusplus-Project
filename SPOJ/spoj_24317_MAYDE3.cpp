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
const int N = 2020002;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int v;

int main(){
    int ans;
    bool isfirst = true;
    for (int i = 0; i < 3; ++ i) {
        scanf("%d",&v);
        if (isfirst) {
            ans = v;
            isfirst = false;
        }
        ans = max(ans, v);
    }
    printf("%d\n",ans);
    return 0;
}
