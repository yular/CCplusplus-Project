/*
*
* Tag: Implementation
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
const int N = 20;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n;

int main(){
    scanf("%d",&n);
    if (n == 1) {
        puts("11");
    } else if (n == 2) {
        puts("11 01");
    } else if (n == 3) {
        puts("06 68 88");
    } else if (n == 4) {
        puts("16 06 68 88");
    } else {
        puts("Glupenky Pierre");
    }
    return 0;
}
