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
const int N = 200030;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int a[3];
int l, w;

int main(){
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    l = w = 0;
    for (int i = 0; i < 3; ++ i) {
        if (l <= a[i]) {
            w = l;
            l = a[i];
        } else if (w <= a[i]){
            w = a[i];
        }
    }
    printf("%d\n",l*w);
    return 0;
}
