/*
*
* Tag: Brute Force
* Time: O(nm)
* Space: O(m)
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
string s, t = "Sandro";

bool sameCase(char s, char t){
    bool res = ( (s >= 'A' && s <= 'Z') && (t >= 'A' && t <= 'Z') ) ||
               ( (s >= 'a' && s <= 'z') && (t >= 'a' && t <= 'z'));
    return  res;
}

int calc(string s){
    int res = 0;
    for (int i = 0; i < t.size(); ++ i) {
        if (s[i] == t[i])
            continue;
        if (!sameCase(s[i], t[i])){
            res += 5;
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
            } else {
                s[i] = toupper(s[i]);
            }
        }
        if (s[i] != t[i]) {
            res += 5;
        }
    }
    return res;
}

int main(){
    cin>>s;
    int ans = INT_MAX, n = s.size(), m = t.size();
    for (int i = 0; i <= n - m; ++ i) {
        ans = min(ans, calc(s.substr(i, m)));
    }
    printf("%d\n",ans);
    return 0;
}
