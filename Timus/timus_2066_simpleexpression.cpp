/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
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
const int M = 260;
const int N = 2000;
const double eps = 1e-8;
const double dinf = 1e15;
const double PI = acos(-1.0);
const int MOD = 100000007;
int arr[N];
string op[]={"++","+-","+*","-+","--","-*","*+","*-","**"};

int opcal(int a, int b, char op){
    switch(op){
        case '+':
            return a+b;
        case '-':
            return a - b;
        case '*':
            return a*b;
    }
}

int cal(){
    int res = INT_MAX;
    for(int i = 0; i < 9; ++ i){
        if(op[i][0] == '*'){
            res = min(res, opcal(opcal(arr[0],arr[1],op[i][0]),arr[2],op[i][1]));
        }else{
            if(op[i][1] == '*'){
                res = min(res, opcal(arr[0],opcal(arr[1],arr[2],op[i][1]),op[i][0]));
            }else{
                res = min(res, opcal(opcal(arr[0],arr[1],op[i][0]),arr[2],op[i][1]));
            }
        }
    }
    return res;
}

int main(){
    int ans = INT_MAX;
    for(int i = 0; i < 3; ++ i){
        scanf("%d",&arr[i]);
    }
    sort(arr, arr + 3);
    do{
        ans = min(ans, cal());
    }while(next_permutation(arr, arr + 3));
    printf("%d\n",ans);
    return 0;
}
