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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 2100002;
const int M = 100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
string name[6]={"Anjan","Sufian","Alim","Shipu","Sohel","Sumon"};
int n;

int main(){
    int cas = 1;
    while (scanf("%d",&n) && n > 0) {
        -- n;
        n = (n%6);
        cout<<"Case "<<cas ++<<": "<<name[n]<<endl;
    }
    return 0;
}
