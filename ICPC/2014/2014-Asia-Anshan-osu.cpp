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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 10005;
const int M = 210000;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        double ans = 0;
        long long pret = 0, prex = 0, prey = 0, curt, curx, cury;
        for (int i = 0; i < n; ++ i) {
            scanf("%lld%lld%lld",&curt,&curx,&cury);
            if (i) {
                ans = max(ans, sqrt((curx - prex)*(curx - prex) + (cury - prey)*(cury - prey))/(double)(curt - pret));
            }
            pret = curt;
            prex = curx;
            prey = cury;
        }
        printf("%.10lf\n",ans);
    }
    return 0;
}
