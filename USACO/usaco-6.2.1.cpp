/*
*
* Tag: String
* Time: O(n)
* Space: O(n)
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include <ctype.h>
#include<fstream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<bitset>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
const int MOD = 9901;
const int INF = 1<<29;
const double ITF = 1e40;
const int N = 20500;
const int M = 22;
const int LIM = 1000000000;
const double eps=1e-8;
const int maxn=750000;
const int maxm=22;
char orgstr[N],nwstr[N];
map<int,int> dict;
int oid, nid, id;
int ans, idx, res;

int IdxofLongestPalindromeSubstr(string &s){
    idx = 0;
    res = 0;
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
    return idx/2 - 1;
}

void work(){
    string s;
    s.resize(nid);
    for(int i = 0; i < nid; ++ i){
        s[i] = nwstr[i];
    }
    id = IdxofLongestPalindromeSubstr(s);
}

int main()
{
    char ch;
    oid = 0, nid = 0;
    while((ch=getchar()) != EOF){
        orgstr[oid] = ch;
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            if(ch >= 'A' && ch <= 'Z')
                ch = ((ch - 'A') + 'a');
            nwstr[nid] = ch;
            dict[nid] = oid;
            ++ nid;
        }
        ++ oid;
    }
    work();
    ans = res - 1;
    printf("%d\n",ans);
    int len = ans/2;
    if(ans%2 == 0)
        -- len;
    int sta = id - len;
    int ed = sta + ans - 1;
    int ssta = dict[sta], eed = dict[ed];
    while(!((orgstr[ssta] >= 'a' && orgstr[ssta] <= 'z') || (orgstr[ssta] >= 'A' && orgstr[ssta] <= 'Z') ))
        ++ ssta;
    while(!((orgstr[eed] >= 'a' && orgstr[eed] <= 'z') || (orgstr[eed] >= 'A' && orgstr[eed] <= 'Z') ))
        -- eed;
    for(int i = ssta; i <= eed; ++ i){
        printf("%c",orgstr[i]);
    }
    puts("");
    return 0;
}
