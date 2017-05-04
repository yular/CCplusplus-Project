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
const int N = 33000;
const int M = 103;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n;
vector<vector<string>> dict(4, vector<string>());
string v, s, arr[4] = {"Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw"};

int getSchoolNum(string sch){
    int res = 0;
    if (sch == "Hufflepuff") {
        res = 1;
    } else if (sch == "Gryffindor") {
        res = 2;
    } else if (sch == "Ravenclaw") {
        res = 3;
    }
    return res;
}

int main(){
    cin>>n;
    getchar();
    for (int i = 0; i < n; ++ i) {
        getline(cin, v);
        getline(cin, s);
        dict[ getSchoolNum(s) ].push_back(v);
    }
    for (int i = 0; i < 4; ++ i) {
        cout<<arr[i]<<":"<<endl;
        for (int j = 0; j < dict[i].size(); ++ j) {
            cout<<dict[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
