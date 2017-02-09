/*
*
* Tag: Math
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
const int N = 10010;
const int M = 50000;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
int n, k, t, cnt;

int main(){
    cnt = 0;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++ i ) {
        scanf("%d",&t);
        if(t%k == 0)
            ++ cnt;
    }
    printf("%d\n",cnt);
    return 0;
}
