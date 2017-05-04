/*
*
* Tag: Number Theory
* Time: O(n^1.5)
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
const int N = 33000;
const int M = 103;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, ans;

bool isPrime(int v){
    for (int i = 2; i*i <= v; ++ i) {
        if (v%i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        if (isPrime(n)) {
            printf("%d\n",n);
        } else if (n%2 == 0){
            ans = n - 3;
            while (!isPrime(ans) || !isPrime(n - ans)) {
                ans -= 2;
            }
            printf("%d %d\n",ans, n - ans);
            continue;
        } else {
            ans = n - 2;
            if (isPrime(ans)) {
                printf("%d 2\n",ans);
                continue;
            }
            ans -= 2;
            while (!isPrime(ans)) {
                ans -= 2;
            }
            printf("%d ",ans);
            n -= ans;
            if (n == 4) {
                puts("2 2");
                continue;
            }
            ans = n - 3;
            while (!isPrime(ans) || !isPrime(n - ans)) {
                ans -= 2;
            }
            printf("%d %d\n",ans, n - ans);
        }
    }
    return 0;
}
