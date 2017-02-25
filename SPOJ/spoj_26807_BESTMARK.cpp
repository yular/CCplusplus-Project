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
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, ans, maxsum, sum, cnt, v;

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        cnt = 0, maxsum = 0;
        for (int i = 0; i < n; ++ i) {
            sum = 0;
            for (int j = 0; j < 3; ++ j) {
                scanf("%d",&v);
                sum += v;
            }
            if (sum > maxsum) {
                maxsum = sum;
                cnt = 1;
            } else if (sum == maxsum){
                ++ cnt;
            }
        }
        printf("%d %d\n", maxsum, cnt);
    }
    return 0;
}
