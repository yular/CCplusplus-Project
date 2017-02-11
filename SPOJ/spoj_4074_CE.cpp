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
const int N = 1000200;
const int M = 50000;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
char expr[N], op;
int a, b, ans;
bool knowOp;

inline int calc(int a, int b, char op){
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a*b;
        default:
            return a/b;
    }
    return 0;
}

int main(){
    int T = 99;
    while (T --) {
        scanf("%s",expr);
        a = b = 0;
        knowOp = false;
        for (int i = 0; expr[i]; ++ i) {
            if (expr[i] >= '0' && expr[i] <= '9') {
                if (knowOp == false) {
                    a = a*10 + (expr[i] - '0');
                } else {
                    b = b*10 + (expr[i] - '0');
                }
            } else {
                op = expr[i];
                knowOp = true;
            }
        }
        ans = calc(a, b, op);
        printf("%d\n",ans);
    }
    return 0;
}
