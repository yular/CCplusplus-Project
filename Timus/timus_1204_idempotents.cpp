/*
*
* Tag: Math
* Time: O(lgn)
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
const int N = 1300;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, p, q, x, y;

void ex_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    ex_gcd(b, a%b, x, y);
    int tmp = x;
    x = y;
    y = tmp - a/b*y;
    return;
}

bool is_prime(int v) {
    for (int i = 2; i * i < v; ++ i) {
        if (v%i == 0) {
            return false;
        }
    }
    return true;
}

void find_prime_factors_of_n(){
    for (int i = 2; i * i < n; ++ i) {
        if ((n % i == 0) && is_prime(i) && is_prime(n/i)) {
            p = i, q = n / i;
            break;
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        find_prime_factors_of_n();
        ex_gcd(p, q, x, y);
        int idempotent_p = p*x < 0? p*x + n : p*x;
        ex_gcd(q, p, x, y);
        int idempotent_q = q*x < 0? q*x + n : q*x;
        if (idempotent_p > idempotent_q) {
            swap(idempotent_p, idempotent_q);
        }
        printf("0 1 %d %d\n",idempotent_p, idempotent_q) ;
    }
    return 0;
}
