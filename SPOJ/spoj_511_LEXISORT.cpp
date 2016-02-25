/*
 *
 * Tag: Sort
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 50010;
const int M = 20;
const double eps = 1e-10;
int n;
string s[N];

bool cmp(const string a, const string &b){
    return a < b;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            cin>>s[i];
        }
        sort(s, s + n, cmp);
        for (int i = 0; i < n; ++ i) {
            cout<<s[i]<<endl;
        }
    }
    return 0;
}
