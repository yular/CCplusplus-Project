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
int que[N], fnt, rear, op, v;

int main(){
    fnt = rear = 0;
    scanf("%d",&n);
    while (n --) {
        scanf("%d",&op);
        if (op == 3) {
            if (fnt < rear) {
                printf("%d\n",que[fnt]);
            } else {
                puts("Empty!");
            }
        } else if ( op == 2 ) {
            if (fnt < rear) {
                ++ fnt;
            }
        } else {
            scanf("%d",&v);
            que[rear ++] = v;
        }
    }
    return 0;
}
