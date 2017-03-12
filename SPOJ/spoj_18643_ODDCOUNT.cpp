/*
*
* Tag: Data Structure
* Time: O(n)
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
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, v;
unordered_map<int, int> dict;
unordered_map<int, int>::iterator it;

int main(){
    dict.clear();
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        ++ dict[v];
    }
    int ans = 0;
    for (it = dict.begin(); it != dict.end(); ++ it) {
        if ((it->second)%2 == 1) {
            ++ ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}
