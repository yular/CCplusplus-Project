/*
*
* Tag: Math
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
const int N = 210002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
string s, ans, dict="0123456789ABCDEF";

char getHex(string t){
    int op = 0;
    for (int i = 3; i >= 0; -- i) {
        if(t[i] == '1')
            op += (1<<(3 - i));
    }
    char res = 0;
    res = dict[op];
    return res;
}

int main(){
    cin>>s;
    int n = (int)s.size(), m = 0;
    m = n%4;
    if (m > 0) {
        string t(m, '0');
        s = t + s;
        n += m;
    }
    for (int i = 0; i < n; i += 4) {
        ans += getHex(s.substr(i, 4));
    }
    cout<<ans<<endl;
    return 0;
}
