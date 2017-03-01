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
const int N = 2000200;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n;
int stk[N], top, op, v;

int main(){
    top = 0;
    scanf("%d",&n);
    while (n --) {
        scanf("%d",&op);
        if (op == 3) {
            if (top > 0) {
                printf("%d\n",stk[top - 1]);
            } else {
                puts("Empty!");
            }
        } else if ( op == 2 ) {
            if (top > 0) {
                -- top;
            }
        } else {
            scanf("%d",&v);
            stk[top ++] = v;
        }
    }
    return 0;
}
