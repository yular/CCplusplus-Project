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
const int N = 2100002;
const int M = 2100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int mark[M], n;

int check(){
    int sum = 0, num_five = 0;
    for (int i = 0; i < n; ++ i){
        if (mark[i] == 3) {
            return 0;
        }
        if (mark[i] == 5) {
            ++ num_five;
        }
        sum += mark[i];
    }
    
    if (num_five == n) {
        return 3;
    }
    
    double avgmark = (double)sum/(double)n;
    if (avgmark > 4.5 || fabs(avgmark - 4.5) < eps ) {
        return 2;
    }
    
    return 1;
}

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i)
        scanf("%d",&mark[i]);
    int type = check();
    switch (type) {
        case 0:
            puts("None");
            break;
        case 1:
            puts("Common");
            break;
        case 2:
            puts("High");
            break;
        case 3:
            puts("Named");
            break;
        default:
            break;
    }
    return 0;
}
