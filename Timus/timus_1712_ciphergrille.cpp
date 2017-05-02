/*
*
* Tag: Implementation
* Time: O(nm)
* Space: o(nm)
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
const int N = 210;
const int M = 10300;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
string mz[N], tmpmz[N], contxt[N], ans;

void decry(){
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < 4; ++ j) {
            if (mz[i][j] == 'X') {
                ans += contxt[i][j];
            }
        }
    }
}

void rotate(){
    for (int i = 0, c = 0; i < 4; ++ i, ++ c) {
        for (int j = 0, r = 3; j < 4; ++ j, -- r) {
            tmpmz[i][j] = mz[r][c];
        }
    }
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < 4; ++ j) {
            mz[i][j] = tmpmz[i][j];
        }
    }
}

int main(){
    ans = "";
    for (int i = 0; i < 4; ++ i) {
        cin>>mz[i];
    }
    for (int i = 0; i < 4; ++ i) {
        cin>>contxt[i];
    }
    for (int i = 0; i < 4; ++ i) {
        decry();
        rotate();
    }
    cout<<ans<<endl;
    return 0;
}
