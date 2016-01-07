#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<climits>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#include<cmath>
#include<list>
#include<sstream>
#include<time.h>
using namespace std;
const int M = 50;
const int N = 100500;
const double eps = 1e-8;
const double dinf = 1e15;
const int MOD = 100000007;
int n,t,topop,topnum;
string stkop[N], stknum[N];
string expr;

void cal(char op){
    string a, b, c;
    string nop = "";
    nop += op;
    switch(op){
        case '(':
                stkop[topop ++] = nop;
                break;
        case '+':
            if(stkop[topop - 1] != "("){
                b = stknum[-- topnum];
                a = stknum[-- topnum];
                c = a;
                c += stkop[-- topop];
                c += b;
           //     cout<<c<<endl;
                stknum[topnum ++] = c;
            }
            stkop[topop ++] = nop;
            break;
        case '-':
            if(stkop[topop - 1] != "("){
                b = stknum[-- topnum];
                a = stknum[-- topnum];
                c = a;
                c += stkop[-- topop];
                c += b;
                stknum[topnum ++] = c;
            }
            stkop[topop ++] = nop;
            break;
        case '*':
             if(stkop[topop - 1] == "*" || stkop[topop - 1] == "/" || stkop[topop - 1] == "^"){
                b = stknum[-- topnum];
                a = stknum[-- topnum];
                c = a;
                c += stkop[-- topop];
                c += b;
                stknum[topnum ++] = c;
             }
             stkop[topop ++] = nop;
             break;
        case '/':
            if(stkop[topop - 1] == "*" || stkop[topop - 1] == "/" || stkop[topop - 1] == "^"){
                b = stknum[-- topnum];
                a = stknum[-- topnum];
                c = a;
                c += stkop[-- topop];
                c += b;
                stknum[topnum ++] = c;
             }
             stkop[topop ++] = nop;
             break;
        case '^':
             stkop[topop ++] = nop;
             break;
        case ')':
            while(stkop[topop - 1] != "("){
                b = stknum[-- topnum];
                a = stknum[-- topnum];
                c = a;
                c += b;
                c += stkop[-- topop];
           //     cout<<c<<endl;
                stknum[topnum ++] = c;
            }
            -- topop;
            break;
    }
}

int main(){
 //   freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T --){
        topop = topnum = 0;
        cin>>expr;
        for(int i = 0; i < expr.size(); ++ i){
            if(expr[i] >= 'a' && expr[i] <= 'z'){
                string val = "";
                val += expr[i];
                stknum[topnum ++] = val;
            }else{
                cal(expr[i]);
            }
        }
        cout<<stknum[topnum - 1]<<endl;
    }
    return 0;
}
