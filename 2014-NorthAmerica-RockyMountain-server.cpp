/*
*
* Tag: Implementation
* Time: O(n)
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
const int M = 50;
const int N = 100500;
const double eps = 1e-8;
const double dinf = 1e15;
const int MOD = 100000007;
int n, t;

int main(){
 //   freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&t) == 2){
        int sum = 0, ans = 0;
        for(int i = 0; i < n; ++ i){
            int v;
            scanf("%d",&v);
            sum += v;
            if(sum <= t)
                ++ ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
