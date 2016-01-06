/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
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
const int M = 50;
const int N = 100500;
const double eps = 1e-8;
const double dinf = 1e15;
const int MOD = 100000007;
string cardnum[N];
int n;
int main(){
    int T;
    cin>>T;
    while(T --){
        cin>>n;
        getchar();
        for(int i = 0; i < n; ++ i){
            getline(cin, cardnum[i]);
        }
        sort(cardnum, cardnum + n);
        for(int i = 0; i < n; ++ i){
            int cnt = 1;
            while(i + 1 < n && cardnum[i] == cardnum[i + 1]){
                ++ cnt;
                ++ i;
            }
           cout<<cardnum[i]<<" "<<cnt<<endl;
        }
    }
    return 0;
}
