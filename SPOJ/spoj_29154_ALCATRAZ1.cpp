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
const int N = 200;
const int M = 50000;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
char num[N];
int sum;

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",num);
        sum = 0;
        for (int i = 0; num[i]; ++ i ) {
            sum += (num[i] - '0');
        }
        printf("%d\n",sum);
    }
    return 0;
}
