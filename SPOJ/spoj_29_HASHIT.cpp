/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
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
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 30;
const int M = 200;
const int MOD = 101;
//const int INF = 1<<29;
int n;
char op[N], str[M];
bool htb[M];
unordered_map<int, string> dict;
unordered_map<string, int> rdict;
int cnt;

void init(){
    memset(htb, 0, sizeof(htb));
    dict.clear();
    rdict.clear();
    cnt = 0;
}

int gethky(){
    int res = 0;
    
    for (int i = 0; str[i]; ++ i) {
        res = (res + ((int)str[i])*(i + 1))%MOD;
    }
    res *= 19;
    res %= MOD;
    for (int j = 0; j <= 19; ++ j) {
        int val = (res + j*j + 23*j)%MOD;
        if (!htb[val]) {
            res = val;
            return res;
        }
    }
    
    res = -1;
    return res;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        init();
        scanf("%d",&n);
        while (n -- ) {
            scanf("%s:%s",op,str);
            strcpy(str, op + 4);
            int key;
            if (op[0] == 'A') {
                if (rdict.find(str) != rdict.end()) {
                    continue;
                }
                key = gethky();
                if (key == -1) {
                    continue;
                }
                htb[key] = 1;
                dict[key] = str;
                rdict[str] = key;
                ++ cnt;
            } else {
                if (rdict.find(str) == rdict.end()) {
                    continue;
                }
                key = rdict[str];
                htb[key] = 0;
                dict.erase(key);
                rdict.erase(str);
                -- cnt;
            }
        }
        printf("%d\n",cnt);
        for (int i = 0; i <= MOD; ++ i) {
            if (htb[i]) {
                string s = dict[i];
                char *ans = new char[s.size() + 1];
                ans[s.size()] = 0;
                memcpy(ans, s.c_str(), s.size());
                printf("%d:%s\n",i,ans);
            }
        }
    }
    return 0;
}
