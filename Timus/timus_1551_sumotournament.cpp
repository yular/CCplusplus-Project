/*
*
* Tag: Implementation
* Time: O(lgn)
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
const int N = 110;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int num[11] = {0,2,4,8,16,32,64,128,256,512,1024};
string a, b;
int n, m;
unordered_map<string, int> dict;

int main(){
    scanf("%d",&n);
    int maxval = 0;
    m = num[n];
    for (int i = 0; i < m; ++ i) {
        cin>>a>>b;
        ++ dict[b];
        maxval = max(maxval, dict[b]);
    }
    int ans = 0;
    while (1) {
        if (maxval <= m/2) {
            ++ ans;
            m >>= 1;
        } else {
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
