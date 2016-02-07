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
const int N = 500;
const double eps = 1e-8;
const double dinf = 1e15;
const double PI = acos(-1.0);
const int MOD = 100000007;
int arr[N];

int main(){
 //   freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T --){
        int n, ans = 0;
        scanf("%d",&n);
        for(int i = 0; i < 12; ++ i)
            scanf("%d",&arr[i]);
        for(int i = 1; i <= 10; ++ i){
            if(arr[i] <= arr[i - 1])
                continue;
            int minval = arr[i];
            for(int j = i; j <= 10; ++ j){
                minval = min(arr[j], minval);
                if(minval > arr[j + 1] && minval > arr[i - 1]){
                    ++ ans;
                }
            }
        }
        printf("%d %d\n",n,ans);
    }
    return 0;
}
