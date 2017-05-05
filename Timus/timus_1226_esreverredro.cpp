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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 33000;
const int M = 103;
const long long MOD = 26;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
string txt;

bool isLattin(char v){
    return (v >= 'A' && v <= 'Z') || ( v >= 'a' && v <= 'z');
}

void reverseStr(int start, int end){
    while (start < end) {
        swap(txt[start], txt[end]);
        ++ start;
        -- end;
    }
}

int main(){
    while (getline(cin, txt)) {
        int i = 0, j = 0;
        for (; i < txt.size(); ++ i){
            while (i < txt.size() && !isLattin(txt[i])) {
                ++ i;
            }
            j = i;
            while(j < txt.size() && isLattin(txt[j])){
                ++ j;
            }
            reverseStr(i, j - 1);
            i = j;
        }
        cout<<txt<<endl;
    }
    return 0;
}
