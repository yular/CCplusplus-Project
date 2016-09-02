/*
*
* Tag: Implementation
* Time: O(nlgn)
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 300;
const int M = 100100;
const long long MOD = 1000000007;
const double eps = 1e-10;
const double pi = acos(-1.0);
struct hero{
    string name;
    int v;
    bool operator < (hero a)const{
        if (v == a.v)
            return name < a.name;
        return a.v < v;
    };
}a[N];
string name;
unordered_map<string, pair<int, int>> ranklist;
int n, m, minrank, maxrank;

int main(){
    while (scanf("%d",&n) && n) {
        ranklist.clear();
        for (int i = 0; i < n; ++ i)
            cin>>a[i].name>>a[i].v;
        sort(a, a + n);
        for (int i = 0; i < n; ++ i) {
            cout<<a[i].name<<" "<<a[i].v<<endl;
        }
        minrank = 0;
        maxrank = 0;
        for (int i = 0; i < n; ++ i) {
            if (i && a[i].v == a[i - 1].v) {
                ++ minrank;
            }else{
                minrank = 1;
                maxrank = i + 1;
            }
            ranklist[a[i].name] = make_pair(maxrank, minrank);
        }
        scanf("%d",&m);
        while (m --) {
            cin>>name;
            cout<<ranklist[name].first;
            if (ranklist[name].second > 1) {
                cout<<" "<<ranklist[name].second;
            }
            cout<<endl;
        }
    }
    return 0;
}
