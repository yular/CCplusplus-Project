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
const int N = 1020;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
string s, t;

bool checkRotate(string s, string t){
    for (int i = 0; i < 4; ++ i) {
        string tmp = s;
        if (s == t) {
            return true;
        }
        s[1] = tmp[2], s[2] = tmp[3], s[3] = tmp[1];
    }
    return false;
}

bool check(){
    string tmp = s;
    //anti-clockwise rotate
    for (int i = 0; i < 3; ++ i) {
        string tmp = s;
        if (checkRotate(tmp, t)) {
            return false;
        }
        tmp[0] = s[1], tmp[1] = s[2], tmp[2] = s[0];
        s = tmp;
    }
    //flip
    s = tmp;
    tmp[0] = s[3], tmp[1] = s[0], tmp[2] = s[2], tmp[3] = s[1];
    if (checkRotate(tmp, t)) {
        return false;
    }
    return true;
}

int main(){
    cin>>s>>t;
    if (check()) {
        puts("different");
    } else {
        puts("equal");
    }
    return 0;
}
