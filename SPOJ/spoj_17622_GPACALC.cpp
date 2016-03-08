/*
 *
 * Tag: Implementation
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 103000;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
int n, tot, sum, p;
char g[M];

int getval(char gp){
    switch (gp) {
        case 'S':
            return 10;
            break;
        case 'A':
            return 9;
            break;
        case 'B':
            return 8;
            break;
        case 'C':
            return 7;
            break;
        case 'D':
            return 6;
            break;
        case 'E':
            return 5;
            break;
    }
    return 0;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        tot = sum = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%d%s",&p,g);
            tot += p;
            sum += p*getval(g[0]);
        }
        printf("%.2lf\n",(double)sum/(double)tot);
    }
    return 0;
}
