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
const int N = 1030;
const int M = 30;
const int MOD = 100;
const double eps = 1e-10;
int n;
char s[N];

int main() {
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%s",s);
        int i = 0, j = strlen(s) - 1;
        bool ispal = true;
        while (i < j) {
            if (s[i] != s[j]) {
                ispal = false;
                break;
            }
            ++ i;
            -- j;
        }
        if (ispal) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
