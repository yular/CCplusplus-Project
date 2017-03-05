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
const int N = 2020002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, v, u;

int main(){
    scanf("%d",&n);
    bool isame = true;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        if (i) {
            if(u != v)
            isame = false;
        }
        u = v;
    }
    if (isame) {
        puts("Verdadero");
    } else {
        puts("Falso");
    }
    return 0;
}
