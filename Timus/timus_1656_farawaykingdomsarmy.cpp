/*
*
* Tag: BFS
* Time: O(n^2)
* Space: O(n^2)
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
const int N = 53000;
const int M = 150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, arr[M], ans[M][M], fnt, rear;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
pair<int, int> q[M], cur, nxt;

void init(){
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            ans[i][j] = -1;
        }
    }
    fnt = rear = 0;
}

bool isInSide(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < n;
}

int main(){
    scanf("%d",&n);
    init();
    for (int i = 0; i < n*n; ++ i)
        scanf("%d",&arr[i]);
    sort(arr, arr + n*n, greater<int>());
    int idx = 1;
    q[rear ++] = make_pair(n/2, n/2);
    ans[n/2][n/2] = arr[0];
    while (fnt < rear && idx < n*n) {
        cur = q[fnt ++];
        for (int i = 0; i < 4; ++ i) {
            nxt.first = cur.first + dir[i][0], nxt.second = cur.second + dir[i][1];
            if (isInSide(nxt.first, nxt.second) && ans[nxt.first][nxt.second] == -1) {
                ans[nxt.first][nxt.second] = arr[idx ++];
                q[rear ++] = nxt;
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
    return 0;
}
