/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
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
const int N = 300;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, speed[N];

int get_min_cross_minefield_time(){
    int res = 0;
    if (n == 1) {
        return speed[0];
    }
    if (n == 2) {
        return max(speed[0], speed[1]);
    }
    
    for (int i = n - 1; i >= 2; i -= 2) {
        if (i >= 3) {
            int time_of_group_include_second_fast = speed[0] + 2*speed[1] + speed[i], time_of_group_include_only_fastest = 2*speed[0] + speed[i - 1] + speed[i];
            res += min(time_of_group_include_only_fastest, time_of_group_include_second_fast);
            if (i == 3) {
                res += speed[1];
            }
        } else {
            res += (speed[0] + speed[1] + speed[2]);
        }
    }
    
    return res;
}

void init() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d",&speed[i]);
    }
}

void sort_people_by_speed(){
    sort(speed, speed + n);
}

int main(){
    init();
    
    sort_people_by_speed();
    
    int ans = get_min_cross_minefield_time();
    printf("%d\n",ans);
    
    return 0;
}
