/*
*
* Tag: Implementation
* Time: O(mn^2)
* Space: O(nm)
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
int course[N][N], n, m;

int cal(int i, int j){
    int st[4] = {0, 0, 0, 0};
    for (int k = 0; k < n; ++ k) {
        if (course[i][k] == 0 && course[j][k] == 0) {
            ++ st[0];
        } else if (course[i][k] == 0 && course[j][k] == 1) {
            ++ st[1];
        } else if(course[i][k] == 1 && course[j][k] == 0) {
            ++ st[2];
        } else {
            ++ st[3];
        }
    }
    return max(max(st[0], st[1]), max(st[2], st[3]));
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            scanf("%d",&course[j][i]);
        }
    }
    int ans = INT_MAX;
    pair<int, int> idx;
    for (int i = 0; i < m - 1; ++ i) {
        for (int j = i + 1; j < m; ++ j) {
            int v = cal(i, j);
            if (ans > v) {
                ans = v;
                idx.first = i + 1, idx.second = j + 1;
            }
        }
    }
    printf("%d\n",ans);
    printf("%d %d\n",idx.first, idx.second);
    return 0;
}
