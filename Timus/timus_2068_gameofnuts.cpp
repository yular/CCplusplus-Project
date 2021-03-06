/*
*
* Tag: Game
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
const int N = 110;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, v, sum;

int main(){
    scanf("%d",&n);
    sum = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&v);
        sum += v/2;
    }
    if (sum%2) {
        puts("Daenerys");
    } else {
        puts("Stannis");
    }
    return 0;
}
