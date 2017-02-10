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
const int N = 200;
const int M = 50000;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-10;
string ans;
string oddwd = " that I hate", evenwd = " that I love", lastwd = " it";
int n;

int main(){
    cin>>n;
    ans = "I hate";
    for (int i = 2; i <= n; ++ i ) {
        if (i%2 == 0) {
            ans += evenwd;
        } else {
            ans += oddwd;
        }
    }
    ans += lastwd;
    cout<<ans<<endl;
    return 0;
}
