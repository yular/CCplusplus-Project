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
const int N = 10002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
string s, ans;
int cnt;

int main(){
    int T;
    cin>>T;
    while (T --) {
        cin>>s;
        ans = "";
        cnt = 0;
        for (int i = 0; i < s.size(); ++ i) {
            if (i == 0 || s[i] != s[i - 1]) {
                if (i > 0 && s[i] != s[i - 1]) {
                    ans += to_string(cnt) + s[i - 1];
                }
                cnt = 1;
            } else {
                ++ cnt;
            }
        }
        ans += to_string(cnt) + s[s.size() - 1];
        cout<<ans<<endl;
    }
    return 0;
}
