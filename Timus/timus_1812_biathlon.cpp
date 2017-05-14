/*
*
* Tag: Implementation
* Time: O(n^2)
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
const int N = 530000;
const int M = 2150;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
struct persion{
    string name;
    double finish_time, running_time;
}p[M];
string ans[M];
int n, num;

bool cmp_finish_time(persion &a, persion &b){
    return a.finish_time < b.finish_time;
}

bool cmp_running_time(persion &a, persion &b){
    return a.running_time < b.running_time;
}

int main(){
    cin>>n;
    double mins = 0, snds = 0;
    for (int i = 0; i < n; ++ i) {
        cin>>p[i].name;
        scanf("%lf:%lf",&mins,&snds);
        p[i].running_time = mins*60 + snds;
        p[i].finish_time = p[i].running_time + 30*i;
    }
    sort(p, p + n, cmp_finish_time);
    num = 0;
    for (int i = 1; i <= n; ++ i) {
        persion *it = min_element(p, p + i, cmp_running_time);
        if ((*it).running_time == p[i - 1].running_time) {
            ans[num ++] = it->name;
        }
    }
    sort(ans, ans + num);
    cout<<num<<endl;
    for (int i = 0; i < num; ++ i) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
