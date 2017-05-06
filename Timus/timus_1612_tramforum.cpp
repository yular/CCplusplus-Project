/*
*
* Tag: Brute Force
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
const int N = 33000;
const int M = 103;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
string txt;
unordered_map<string, int> dict;
int trmcnt, trycnt;

bool isLattin(char v){
    return (v >= 'a' && v <= 'z');
}

int main(){
    trmcnt = trycnt = 0;
    while (getline(cin, txt)) {
        string s = "";
        for (int i = 0; i < txt.size(); ++ i) {
            s = "";
            if (!isLattin(txt[i])) {
                continue;
            }
            while (i < txt.size() && isLattin(txt[i])) {
                s += txt[i];
                ++ i;
            }
            if (s == "tram") {
                ++ trmcnt;
            }
            if (s == "trolleybus") {
                ++ trycnt;
            }
        }
    }
    if (trmcnt > trycnt) {
        cout<<"Tram driver"<<endl;
    } else if (trmcnt < trycnt) {
        cout<<"Trolleybus driver"<<endl;
    } else {
        cout<<"Bus driver"<<endl;
    }
    return 0;
}
