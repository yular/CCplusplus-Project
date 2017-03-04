/*
*
* Tag: Hash
* Time: O(1)
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
const int N = 2020002;
const int M = 300;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
unordered_map<double, unordered_set<double>> dict;
int q;
double x, y;

int main(){
    dict.clear();
    while (scanf("%d",&q) == 1) {
        scanf("%lf%lf",&x,&y);
        printf("%d %.6lf %.6lf\n",q,x,y);
        if (q == 1) {
            if (dict.find(x) != dict.end() && dict[x].find(y) != dict[x].end()) {
                puts("Yes");
            } else {
                puts("No");
            }
        } else {
            dict[x].insert(y);
        }
        puts("");
    }
    return 0;
}
