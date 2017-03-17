/*
*
* Tag: Math
* Time: O(n^1.5)
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
const int N = 2100002;
const int M = 2100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, num, v;
int p[M];

void init(){
    num = 0;
    bool isprime = true;
    for (int i = 2; i < 2400; ++ i ) {
        isprime = true;
        for (int j = 2; j <= sqrt(i); ++ j) {
            if (i%j == 0) {
                isprime = false;
            }
        }
        if (isprime) {
            p[num ++] = i;
        }
    }
}

bool check(int v){
    int cnt = 0;
    for (int i = 0; i < num && v >= p[i]; ++ i) {
        if (v%p[i] == 0) {
            ++ cnt;
        }
        if (cnt >= 3) {
            break;
        }
    }
    return cnt >= 3;
}

int main(){
    init();
    scanf("%d",&n);
    bool isprime_3 = true;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        if (!check(v)) {
            isprime_3 = false;
        }
    }
    if (isprime_3) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
