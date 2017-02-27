/*
*
* Tag: Implementation
* Time: O(n^2)
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
const int N = 200200;
const int M = 1300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, p, spcnt;

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&p);
        if ( p == 1 ) {
            spcnt = n - 1;
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < spcnt; ++ j) {
                    printf(" ");
                }
                for (int j = 0; j < 2*i + 1; ++ j) {
                    printf("*");
                }
                -- spcnt;
                puts("");
            }
        } else {
            spcnt = 0;
            for (int i = n - 1; i >= 0; -- i) {
                for (int j = 0; j < spcnt; ++ j) {
                    printf(" ");
                }
                for (int j = 0; j < 2*i + 1; ++ j) {
                    printf("*");
                }
                ++ spcnt;
                puts("");
            }
        }
    }
    return 0;
}
