/*
*
* Tag: DP
* Time: O(m(b-a)) where m is the length of input string
* Space: O(2^a + 2^(a + 1) + ... + 2^(b))
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
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
const int INF = 2000000020;
const double ITF = 1e40;
const int N = 10100;
const int M = 110;
ifstream fin("contact.in");
ofstream fout("contact.out");
struct patten{
    int freq;
    string val;
    bool operator < (const patten a)const{
        if(freq == a.freq){
            if(val.size() == a.val.size())
                return val < a.val;
            return val.size() < a.val.size();
        }
        return a.freq < freq;
    }
}arr[N];
int mask[] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191};
map<string, int> dp;
int a, b, n, cnt = 0;

string printBin(int val, int bit){
    string res = "";
    if(!val){
        string ans(bit, '0');
        return ans;
    }
    int cnt = 0;
    while(val){
        if(val&1){
            res += '1';
        }else{
            res += '0';
        }
        val >>= 1;
        ++ cnt;
    }
    while(cnt < bit){
        res += '0';
        ++ cnt;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    fin>>a>>b>>n;
    string str = "", inpt = "";
    while(fin>>inpt){
        str += inpt;
    }
    int i = 0, val = 0;
    int m = str.size();
    for(; i < min(a - 1, m); ++ i){
        int idx = str[i] - '0';
        val = ((val<<1)|idx);
    }
    int len = a;
    for(; i < str.size(); ++ i){
        int idx = str[i] - '0';
        val = ((val<<1)|idx);
        for(int j = a; j <= len; ++ j){
            int res = val&mask[j];
            string k = printBin(res, j);
            if(dp.find(k) == dp.end())
                dp[k] = 1;
            else
                ++ dp[k];
        }
        if(len < b)
            ++ len;
    }
    map<string,int>::iterator it = dp.begin();
    for(; it != dp.end(); ++ it){
        arr[cnt].val = it->first;
        arr[cnt].freq = it->second;
        ++ cnt;
    }
    sort(arr, arr + cnt);
    int idx = 0, tot = 0;
    for(int i = 0; i < cnt; ++ i){
        fout<<arr[i].freq<<endl;
        int freq = arr[i].freq;
        bool isfirst = true;
        int num = 0;
        while(i < cnt && arr[i].freq == freq){
            if(!isfirst && num == 0)
                fout<<endl;
            else if(!isfirst)
                fout<<" ";
            fout<<arr[i].val;
            //cout<<i;
            isfirst = false;
            num = (num + 1)%6;
            ++ i;
        }
        fout<<endl;
        -- i;
        ++ tot;
        if(tot >= n)
            break;
    }
    return 0;
}
