/*
*
* Tag: Implementation
* Time: O(nlgn)
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
const int N = 50200;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, x, pos[N];

int main(){
    scanf("%d%d",&n,&x);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&pos[i]);
    }
    pos[n ++] = 0;
    pos[n ++] = x;
    sort(pos, pos + n);
    int idx = 0;
    for(int i = 0; i < n; ++ i){
        if (pos[i] == 0) {
            idx = i;
            break;
        }
    }
    if (pos[idx - 1] != x && pos[idx + 1] != x) {
        puts("Impossible");
    } else if (pos[idx - 1] == x){
        printf("%d %d\n",2*pos[idx + 1] - x, -x);
    } else {
        printf("%d %d\n", x, -2*pos[idx - 1] + x);
    }
    return 0;
}
