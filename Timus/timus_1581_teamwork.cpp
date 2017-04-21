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
const int N = 10050;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n, arr[N];

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i)
        scanf("%d",&arr[i]);
    arr[n ++] = -1;
    int cnt = 0;
    bool isfirst = true;
    for (int i = 0; i < n; ++ i) {
        if (i == 0 || arr[i] == arr[i - 1]) {
            ++ cnt;
        } else {
            if (!isfirst) {
                printf(" ");
            }
            printf("%d %d",cnt,arr[i - 1]);
            isfirst = false;
            cnt = 1;
        }
    }
    puts("");
    return 0;
}
