/*
*
* Tag: String (KMP)
* Time: O(n)
* Space: O(n)
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
const int N = 30;
const int M = 300010;
const int MOD = 10037;
const double eps = 1e-6;
int n;
string s,t;
int nxt[M];

void getnext(){
    int i = 0, j = -1;
    nxt[0] = -1;
    while (t[i]) {
        if (j == -1 || t[i] == t[j]) {
            ++ i;
            ++ j;
            nxt[i] = j;
        }else{
            j = nxt[j];
        }
    }
}

int kmp(string &s, string &t, int ls, int lt){
//    printf("%d %d\n",ls,lt);
//    puts(s);
//    puts(t);
    int i = 0, j = 0;
    while (i < ls && j < lt) {
        if (i == -1 || t[j] == s[i]) {
            ++ i;
            ++ j;
        } else {
            i = nxt[i];
        }
    }
    if (i >= ls) {
        return j - ls;
    } else {
        return -1;
    }
}


int main(){
//    freopen("fence4.in", "r", stdin);
//    freopen("fence4.out", "w", stdout);
    cin>>n;
    cin>>s>>t;
    if (s == t) {
        puts("0");
    } else {
        s += s;
        getnext();
        int ans = kmp(t, s, (int)t.size(), (int)s.size());
        if (ans == -1) {
            puts("-1");
        } else {
            printf("%d\n",n-ans);
        }
    }
    return 0;
}
