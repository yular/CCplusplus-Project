/*
*
* Tag: Data Structure (Hash Map)
* Time: O(n^2)
* Space: O(n)
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
int a[M], b[M], c, n;
unordered_map<int,int> mp;

int main(){
    scanf("%d",&n);
    mp.clear();
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&b[i]);
    }
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&c);
        ++ mp[c];
    }
    int sum = 0, ans = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            sum = a[i] + b[j];
            if (mp.find(-sum) != mp.end()) {
                ans += mp[-sum];
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
