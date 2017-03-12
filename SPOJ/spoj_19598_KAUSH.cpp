/*
*
* Tag: Implementation
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
string v, iv, dv;

int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        cin>>v;
        iv = "", dv = "";
        int idx = v.find('.');
        if (idx == -1) {
            cout<<v<<endl;
        } else {
            iv = v.substr(0, idx);
            ++ idx;
            while (v[idx] == '0' && idx < v.size()) {
                ++ idx;
            }
            dv = v.substr(idx);
            cout<<iv<<' '<<dv<<endl;
        }
    }
    return 0;
}
