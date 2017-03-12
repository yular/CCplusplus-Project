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
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, m;
int ntu_cnt, ske_cnt;

int calc(int v){
    int res = 0;
    while (v > 0) {
        if ((v&1) != 0)
            ++ res;
        v >>= 1;
    }
    return res;
}

int main(){
    while (scanf("%d%d",&n,&m)) {
        if (n == 0 && m == 0) {
            break;
        }
        ntu_cnt = calc(abs(n));
        ske_cnt = calc(abs(m));
        if ((ntu_cnt + ske_cnt)%2 == 0) {
            puts("Naruto Wins :)");
        } else {
            puts("SasUke Wins :(");
        }
    }
    return 0;
}
