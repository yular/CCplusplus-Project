/*
 *
 * Tag: String (Manacher)
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
const int N = 1500;
const int M = 120;
const double eps = 1e-10;
int n;
string s;

int IdxofLongestPalindromeSubstr(string &s){
    int idx = 0, res = 0;
    int n = s.size();
    string s1;
    s1.resize(2*n + 2);
    vector<int> p(2*n + 2, 0);
    s1[0] = '$';
    s1[1] = '#';
    for(int i = 0; i < n; ++ i){
        s1[(i + 1)<<1] = s[i];
        s1[((i + 1)<<1) + 1] = '#';
    }
    for(int id = 0, i = 1; i < s1.size(); ++ i){
        if(p[id] + id > i)
            p[i] = min(p[2*id - i], p[id] + id - i);
        else
            p[i] = 1;
        while(s1[p[i] + i] == s1[i - p[i]]) ++ p[i];
        if(i + p[i] > id + p[id])
            id = i;
        if(res < p[i]){
            res = max(res, p[i]);
            idx = i;
        }
    }
    //return the idx of center of longest palindrome substring
    //res is the length of longest palindrome substring
    return res;
}

int main() {
    cin>>n>>s;
    int ans = IdxofLongestPalindromeSubstr(s);
    printf("%d\n",ans - 1);
    return 0;
}
