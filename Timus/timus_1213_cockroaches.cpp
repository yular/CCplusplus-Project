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
const int N = 1530000;
const int M = 2150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
unordered_set<string> node;
string s, fs, snds;

int main(){
    cin>>s;
    node.clear();
    node.insert(s);
    while (cin>>s) {
        if (s == "#") {
            break;
        }
        size_t idx = s.find('-');
        fs = s.substr(0, idx);
        snds = s.substr(idx + 1);
        //cout<<fs<<" "<<snds<<endl;
        node.insert(fs);
        node.insert(snds);
    }
    cout<<node.size() - 1<<endl;
    return 0;
}
