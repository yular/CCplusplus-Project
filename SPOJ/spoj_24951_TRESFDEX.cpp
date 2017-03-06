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
const int N = 10002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int x[3];

int cal(int x){
    return x*x - 3*x + x%10;
}

int main(){
    for (int i = 0; i < 3; ++ i) {
        scanf("%d",&x[i]);
    }
    printf("%d %d %d\n",cal(x[0]), cal(x[1]), cal(x[2]));
    return 0;
}
