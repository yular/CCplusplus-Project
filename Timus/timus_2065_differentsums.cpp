/*
*
* Tag: Construction
* Time: O(m)
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
const int N = 33000;
const int M = 103;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, m;

void printZero(){
    for (int i = 0; i < n - m; ++ i) {
        printf(" 0");
    }
    puts("");
}

int main(){
    scanf("%d%d",&n,&m);
    printf("0");
    if (m&1) {
        for (int i = 1; i <= m/2; ++ i) {
            printf(" %d %d",i,-i);
        }
        printZero();
    } else {
        for (int i = 1; i < m/2; ++ i) {
            printf(" %d %d",i,-i);
        }
        printf(" %d",m/2);
        printZero();
    }
    return 0;
}
