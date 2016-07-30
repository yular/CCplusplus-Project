/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
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
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 10005;
const int M = 210000;
const long long MOD = 1000000007;
const double eps = 1e-10;
pair<int,int> info[N];
int n;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.first < b.first;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas){
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d",&info[i].first,&info[i].second);
        }
        sort(info, info + n, cmp);
        double ans = 0.0;
        for (int i = 1; i < n; ++ i) {
            ans = max(ans, fabs(info[i].second - info[i - 1].second)/(double)(info[i].first - info[i - 1].first));
        }
        printf("Case #%d: %.2lf\n",cas,ans);
    }
    return 0;
}
