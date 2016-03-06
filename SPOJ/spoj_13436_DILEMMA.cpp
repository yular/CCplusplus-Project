/*
 *
 * Tag: String
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 1300;
const int M = 300;
const int MOD = 100;
const double eps = 1e-10;
string a, b;
int n;

int main() {
    cin>>a>>b;
    if (a+b >= b+a) {
        cout<<a+b<<endl;
    } else {
        cout<<b+a<<endl;
    }
    return 0;
}
