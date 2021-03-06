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
const int M = 10300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n;
string guess;

int main(){
    cin>>n;
    int ans = 2;
    for (int i = 0; i < n; ++ i) {
        cin>>guess;
        ++ ans;
        if (guess.find('+') != string::npos) {
            ++ ans;
        }
    }
    if (ans == 13) {
        ++ ans;
    }
    printf("%d\n",ans*100);
    return 0;
}
