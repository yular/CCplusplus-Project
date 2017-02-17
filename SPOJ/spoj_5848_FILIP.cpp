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
const int N = 30;
const int M = 100;
const int NN = 1010;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
string fnum, snum;

int main(){
    cin>>fnum>>snum;
    reverse(fnum.begin(), fnum.end());
    reverse(snum.begin(), snum.end());
    if (fnum > snum) {
        cout<<fnum<<endl;
    } else {
        cout<<snum<<endl;
    }
    return 0;
}
