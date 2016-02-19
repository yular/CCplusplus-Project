/*
*
* Tag: Bit Manipulation
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 110;
const int M = 101010;
const double eps = 1e-10;
int p, q;

int main() {
    scanf("%d%d",&p,&q);
    printf("%d\n",p^q);
    return 0;
}
