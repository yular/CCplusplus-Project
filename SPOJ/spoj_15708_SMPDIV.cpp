/*
*
* Tag: Math
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 110;
const int M = 101010;
const double eps = 1e-10;
int n, x, y;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d%d",&n,&x,&y);
        bool isfirst = true;
        for (int i = x; i < n; ++ i) {
            if (i%x == 0 && i%y != 0) {
                if (!isfirst) {
                    printf(" ");
                }
                printf("%d",i);
                isfirst = false;
            }
        }
        puts("");
    }
    return 0;
}
