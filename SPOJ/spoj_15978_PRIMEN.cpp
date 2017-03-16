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
const int N = 210002;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
bool isprime[M];
int n;

void init(){
    memset(isprime, true, sizeof(isprime));
    isprime[1] = 1;
    for (int i = 2; i < M; ++ i) {
        for (int j = 2; j <= sqrt(i); ++ j) {
            if (i%j == 0) {
                isprime[i] = 0;
            }
        }
    }
}

int main(){
    init();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        for (int i = 1; i <= n; ++ i) {
            if (isprime[i] == 1) {
                printf("%d\n",i);
            }
        }
        if (T) {
            puts("");
        }
    }
    return 0;
}
