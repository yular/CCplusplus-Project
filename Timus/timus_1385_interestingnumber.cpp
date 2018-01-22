/*
*
* Tag: Math
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
const int N = 1300;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n;

int main(){
    scanf("%d",&n);
    if (n == 1) {
        puts("14");
    } else if (n == 2){
        puts("155");
    } else {
        printf("1575");
        for (int i = 0; i < n - 3; ++ i) {
            printf("0");
        }
        puts("");
    }
    return 0;
}
