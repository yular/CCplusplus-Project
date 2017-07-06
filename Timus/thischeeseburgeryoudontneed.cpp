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
const int N = 110;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
string s;

void solve(const string &s, bool next_sen) {
    int obj_l = s.find('{'), obj_r = s.find('}');
    int sub_l = s.find('('), sub_r = s.find(')');
    int veb_l = s.find('['), veb_r = s.find(']');
    string obj(s.substr(obj_l + 1, obj_r - obj_l - 1));
    string sub(s.substr(sub_l + 1, sub_r - sub_l - 1));
    string veb(s.substr(veb_l + 1, veb_r - veb_l - 1));
    
    if (!next_sen) {
        obj[0] = toupper(obj[0]);
    } else {
        obj[0] = tolower(obj[0]);
    }
    sub[0] = tolower(sub[0]);
    veb[0] = tolower(veb[0]);
    
    cout<<obj<<" "<<sub<<" "<<veb;
}

inline bool isbnd(char c){
    return c == '[' || c == '{' || c == '(';
}

int main(){
    getline(cin, s);
    size_t compos = s.find(',');
    if (compos == string::npos) {
        solve(s, 0);
    } else {
        size_t curpos = compos;
        while (!isbnd(s[curpos])) {
            ++ curpos;
        }
        solve(s.substr(0, compos), 0);
        cout<<s.substr(compos, curpos - compos);
        solve(s.substr(curpos, s.size() - curpos + 1), 1);
        puts("");
    }
    return 0;
}
