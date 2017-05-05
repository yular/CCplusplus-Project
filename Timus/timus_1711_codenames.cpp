/*
*
* Tag: Brute Force
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
int n, v;
bool notfind;
vector<vector<string>> input;
vector<string> ans;

int main(){
    cin>>n;
    input.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; ++ i) {
        input[i].resize(3);
        cin>>input[i][0]>>input[i][1]>>input[i][2];
        sort(input[i].begin(), input[i].end());
    }
    notfind = false;
    string cur = "";
    for (int i = 0; i < n; ++ i) {
        cin>>v;
        bool isfind = false;
        if (i == 0) {
            ans[i] = cur = input[v - 1][0];
            isfind = true;
        } else {
            for (int j = 0; j < 3; ++ j) {
                if (input[v - 1][j] > cur) {
                    isfind = true;
                    ans[i] = cur = input[v - 1][j];
                    break;
                }
            }
        }
        if (!isfind) {
            notfind = true;
        }
        
    }
    if (!notfind) {
        for (int i = 0; i < n; ++ i) {
            cout<<ans[i]<<endl;
        }
    } else {
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
