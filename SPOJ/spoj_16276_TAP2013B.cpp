/*
*
* Tag: Implementation
* Time: O(nlgn)
* Space: O(lgn)
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
int n, v[M], sum;

int main(){
    scanf("%d",&n);
    sum = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v[i]);
        sum += v[i];
    }
    sort(v, v + n, greater<int>());
    if (v[0]*100/sum >= 45 || ( v[0]*100/sum >= 40 && v[0]*10 >= v[1]*10  + sum)) {
        puts("1");
    } else {
        puts("2");
    }
    return 0;
}
