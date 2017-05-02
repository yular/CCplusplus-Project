/*
*
* Tag: Brute Force
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
const int N = 210;
const int M = 10300;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int dir[16][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}};
int n, r, c, nr, nc;
long long ans;

bool isInBnd(int dr, int dc){
    return dr >= 1 && dr <= n && dc >= 1 && dc <= n;
}

void calcKing(){
    ans = 0;
    for (int i = 0; i < 8; ++ i) {
        nr = r + dir[i][0], nc = c + dir[i][1];
        if (isInBnd(nr, nc)) {
            ++ ans;
        }
    }
}

void calcKnight(){
    ans = 0;
    for (int i = 8; i < 16; ++ i) {
        nr = r + dir[i][0], nc = c + dir[i][1];
        if (isInBnd(nr, nc)) {
            ++ ans;
        }
    }
}

void calcBishop(){
    ans = min(r - 1, c - 1) + min(n - r, c - 1) + min(r - 1, n - c) + min(n - r, n - c);
}

void calcRook(){
    ans = 2*(n - 1);
}

void calcQueen(){
    ans = min(r - 1, c - 1) + min(n - r, c - 1) + min(r - 1, n - c) + min(n - r, n - c) + 2*(n - 1);
}

int main(){
    scanf("%d%d%d",&n,&r,&c);
    calcKing();
    printf("King: %lld\n",ans);
    calcKnight();
    printf("Knight: %lld\n",ans);
    calcBishop();
    printf("Bishop: %lld\n",ans);
    calcRook();
    printf("Rook: %lld\n",ans);
    calcQueen();
    printf("Queen: %lld\n",ans);
    return 0;
}
