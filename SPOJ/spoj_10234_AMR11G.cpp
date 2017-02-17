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
const int N = 200030;
const int M = 300;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
char cord[M];
bool canReach;

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",cord);
        canReach = true;
        for (int i = 0; cord[i]; ++ i) {
            if (cord[i] == 'D') {
                canReach = false;
                break;
            }
        }
        if (canReach) {
            puts("Possible");
        } else {
            puts("You shall not pass!");
        }
    }
    return 0;
}

