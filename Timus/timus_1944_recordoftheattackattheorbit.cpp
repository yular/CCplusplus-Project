/*
*
* Tag: Implementation
* Time: (max_x - min_x)*(max_y - min_y)
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
const int N = 33000;
const int M = 550;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
pair<int, int> pnt[M];
int n, max_x, min_x, max_y, min_y;

bool cmp(pair<int,int> &a, pair<int, int> &b){
    return a.second == b.second ? a.first < b.first : b.second < a.second;
}

int main(){
    scanf("%d",&n);
    min_x = min_y = max_y = max_x = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d",&pnt[i].first,&pnt[i].second);
        min_x = min(min_x, pnt[i].first);
        max_x = max(max_x, pnt[i].first);
        min_y = min(min_y, pnt[i].second);
        max_y = max(max_y, pnt[i].second);
    }
    sort(pnt, pnt + n, cmp);
    int idx = 0;
    for (int i = max_y; i >= min_y; -- i) {
        for (int j = min_x; j <= max_x; ++ j) {
            if (idx < n && j == pnt[idx].first && i == pnt[idx].second) {
                printf("*");
                ++ idx;
                continue;
            }
            if (i == 0 && j == 0) {
                printf("+");
            } else if(i == 0) {
                printf("-");
            } else if (j == 0){
                printf("|");
            } else {
                printf(".");
            }
        }
        puts("");
    }
    return 0;
}
