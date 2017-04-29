/*
*
* Tag: Math
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
const int N = 200;
const int M = 100300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int note[6]={10, 50, 100, 500, 1000, 5000}, p;
int arr[N], ansarr[M];

int main(){
    int sum = 0, t = 0;
    for (int i = 0; i < 6; ++ i) {
        scanf("%d",&arr[i]);
        sum += arr[i]*note[i];
        if (t == 0 && arr[i] > 0) {
            t = note[i];
        }
    }
    scanf("%d",&p);
    int idx = 0;
    for (int i = sum - t + 1; i <= sum; ++ i) {
        if (i%p == 0) {
            ansarr[idx ++] = i/p;
        }
    }
    printf("%d\n",idx);
    for (int i = 0; i < idx; ++ i) {
        printf("%d ",ansarr[i]);
    }
    puts("");
    return 0;
}
