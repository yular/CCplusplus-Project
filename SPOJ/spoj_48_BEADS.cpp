/*
*
* Tag: String
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
using namespace std;
const int N = 20005;
const int M = 10005;
const int MOD = 10037;
char s[N], t[M];

int smallestRepresentation(){
    int i = 0, j = 1, k = 0, n = strlen(t);
    strcpy(s, t);
    strcat(s, t);
    while (i < n && j < n && k < n) {
        if (i == j) {
            ++ j;
        }
        if (s[i + k] == s[j + k]) {
            ++ k;
        } else {
            s[i + k] > s[j + k] ? i += k + 1 : j += k + 1, k = 0;
        }
    }
    return i;
}

int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while (T --) {
        gets(t);
        printf("%d\n",smallestRepresentation()+1);
    }
    return 0;
}
