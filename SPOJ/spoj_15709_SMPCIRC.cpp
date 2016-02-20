/*
 *
 * Tag: Math
 * Time: O(1)
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
const int N = 310;
const int M = 101010;
const double eps = 1e-10;
int n;
pair<int, int> o[2];
int r[2];

char solve(){
    char res = 'O';
    double dis = sqrt((o[0].first - o[1].first)*(o[0].first - o[1].first) + (o[0].second - o[1].second)*(o[0].second - o[1].second));
    int sr = min(r[0], r[1]), lr = max(r[0], r[1]);
    double sumr = sr + dis;
    if (sumr < lr) {
        res = 'I';
    } else if (fabs(sumr - lr) < eps) {
        res = 'E';
    } else {
        res = 'O';
    }
    return res;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        for (int i = 0; i < 2; ++ i) {
            scanf("%d%d%d",&o[i].first,&o[i].second,&r[i]);
        }
        printf("%c\n",solve());
    }
    return 0;
}
