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

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        int n, ans = 0;
        scanf("%d",&n);
        int val;
        for(int i = 0; i < 20; ++ i){
            scanf("%d",&val);
            int j = 0;
            for(j = 0; j < i; ++ j){
                if(arr[j] > val){
                    for(int k = i; k > j; -- k){
                        arr[k] = arr[k - 1];
                        ++ ans;
                    }
                    break;
                }
            }
            arr[j] = val;
        }
        printf("%d %d\n",n,ans);
    }
    return 0;
}
