/*
 *
 * Tag: String
 * Time: O(n)
 * Space: O(n)
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
const int N = 10020;
const int M = 120;
const double eps = 1e-10;
int cnt;
char s[N];

int main() {
    scanf("%s",s);
    cnt = 0;
    for (int i = 0; s[i]; ++ i) {
        if (s[i] =='A' || s[i] == 'a') {
            ++ cnt;
        } else if (s[i] == 'E' || s[i] == 'e') {
            ++ cnt;
        } else if (s[i] == 'I' || s[i] == 'i') {
            ++ cnt;
        } else if (s[i] == 'O' || s[i] == 'o') {
            ++ cnt;
        } else if (s[i] == 'U' || s[i] == 'u') {
            ++ cnt;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
