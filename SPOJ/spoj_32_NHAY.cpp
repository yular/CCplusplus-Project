/*
*
* Tag: String (KMP)
* Time: O(n^2)
* Space: O(n)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 1000010;
const int M = 1000010;
int n;
char s[N], t[M];
int nxt[M];

void getnext(){
    int i = 0, j = -1;
    nxt[0] = -1;
    while (s[i]) {
        if (j == -1 || s[i] == s[j]) {
            ++ i;
            ++ j;
            nxt[i] = j;
        }else{
            j = nxt[j];
        }
    }
}

int kmp(char *s, char *t, int ls, int lt, int idx){
    int i = 0, j = idx;
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

int main() {

    while (scanf("%d",&n) == 1) {
        scanf("%s%s",s,t);
        int i = 0;
        int len = strlen(t);
        getnext();
        while (i < len) {
            int ans = kmp(s, t, n, len, i);
            if (ans == -1) {
                break;
            }
            printf("%d\n",ans);
            i = ans + 1;
        }
        puts("");
    }
    return 0;
}
