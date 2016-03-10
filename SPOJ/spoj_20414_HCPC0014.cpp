/*
 *
 * Tag: Implementation
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
const int N = 100010;
const int M = 130;
const long long MOD = 1000000007;
const double eps = 1e-10;
int n, a, b;
char s[M];

int cal(char op){
    switch (op) {
        case '+':
            return a + b;
        
        case '-':
            return a - b;
            
        case '*':
            return a * b;
            
        case '/':
            return a / b;
    }
    return 0;
}


int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s%d%d",s,&a,&b);
        printf("%d\n",cal(s[0]));
    }
    return 0;
}
