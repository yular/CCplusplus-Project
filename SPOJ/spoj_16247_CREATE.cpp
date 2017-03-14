/*
*
* Tag: String
* Time: O(n)
* Space: O(n)
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
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
string s, p;

int main(){
    int T;
    cin>>T;
    getchar();
    while (T --) {
        getline(cin, p);
        getline(cin, s);
        if (s.find(p) != -1) {
            puts("possible");
        } else {
            puts("not possible");
        }
    }
    return 0;
}
