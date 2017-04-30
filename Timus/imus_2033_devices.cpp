/*
*
* Tag: Data Structure
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
const int N = 200;
const int M = 10300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
string pname, dname;
int price;
unordered_map<string, int> dcnt, dprice;
unordered_map<string, int>::iterator it;

int main(){
    dcnt.clear();
    dprice.clear();
    int maxcnt = 0;
    while (cin>>pname) {
        cin>>dname;
        cin>>price;
        ++ dcnt[dname];
        if (dprice.count(dname) == 0) {
            dprice[dname] = price;
        }
        dprice[dname] = min(dprice[dname], price);
        maxcnt = max(maxcnt, dcnt[dname]);
    }
    string ans = "";
    int minprice = INT_MAX;
    for (it = dcnt.begin(); it != dcnt.end(); ++ it) {
        if (it->second == maxcnt) {
            dname = it->first;
            if (dprice[dname] < minprice) {
                minprice = dprice[dname];
                ans = dname;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
