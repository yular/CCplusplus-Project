/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
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
const int mod = 47;
const int N=200;
const int M = 250000;
ifstream fin("preface.in");
ofstream fout("preface.out");
char ch[7]={'I','V','X','L','C','D','M'};
int t[100];
int n;

void getRome(int n){
    if (n >=1000){
        t['M']++;
        getRome(n-1000);
    }else if (n >=900){
        t['C']++;
        t['M']++;
        getRome(n-900);
    }else if (n >=500){
        t['D']++;
        getRome(n-500);
    }
    else if (n >=400){
            t['C']++;
            t['D']++;
            getRome(n-400);
        }
        else if (n >=100){
            t['C']++;
            getRome(n-100);
        }
        else if (n >=90){
            t['X']++;
            t['C']++;
            getRome(n-90);
        }
        else if (n >=50){
            t['L']++;
            getRome(n-50);
        }
        else if (n >=40){
            t['X']++;
            t['L']++;
            getRome(n-40);
        }
        else if (n >=10){
            t['X']++;
            getRome(n-10);
        }
        else if (n >=9){
            t['I']++;
            t['X']++;
            getRome(n-9);
        }
        else if (n >=5){
            t['V']++;
            getRome(n-5);
        }
        else if(n >=4){
            t['I']++;
            t['V']++;
            getRome(n-4);
        }
        else if (n >=1){
            t['I']++;
            getRome(n-1);
        }
}

int main(){
    fin>>n;
    memset(t, 0, sizeof(t));
    for(int i = 1; i <= n; ++ i)
        getRome(i);
    for(int i = 0; i <= 6; ++ i){
        if(t[ch[i]])
            fout<<ch[i]<<" "<<t[ch[i]]<<endl;
    }
    return 0;
}
