/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
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
const int N = 100010;
const int M = 50000;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
vector<pair<string, int>> arr;
string name;
int age;

bool cmp(pair<string, int> &a, pair<string, int> &b){
    return a.second == b.second ? a.first < b.first : b.second < a.second;
}

int main(){
    arr.clear();
    while (cin>>name>>age) {
        arr.push_back(make_pair(name, age));
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < arr.size(); ++ i) {
        cout<<arr[i].first<<endl;
    }
    return 0;
}
