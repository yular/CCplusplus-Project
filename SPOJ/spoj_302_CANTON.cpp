/*
*
* Tag: Math (Binary Search)
* Time: O(lgn)
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
const int M = 10300;
const int N = 1000010;
const double eps = 1e-8;
const double dinf = 1e15;
const double PI = acos(-1.0);
const int MOD = 100000007;
pair<int,long long> p[2];
int n;

int getsum(int val){
    return val*(val+1)/2;
}

int main(){
 //   freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int l = 1, r = M;
        int ans = 0, op = -1;
        while(l <= r){
            int mid = (l + r)>>1;
            int sum = getsum(mid), sumup = getsum(mid + 1);
            if(sum == n){
                ans = mid;
                op = 0;
                break;
            }else if(sum < n && sumup >= n){
                ans = mid + 1;
                op = 1;
                break;
            }else if(sumup < n){
                l = mid + 1;
            }else if(sum > n){
                r = mid - 1;
            }
        }
        if(!op){
            if(ans%2 == 0){
                printf("TERM %d IS %d/1\n",n,ans);
            }else{
                printf("TERM %d IS %d/1\n",n,ans);
            }
        }else if(op == 1){
            int divsor = 1, dividen = ans;
            int dif = n - (ans-1)*ans/2 - 1;
            if(ans%2 == 0){
                divsor = 1, dividen = ans;
                divsor += dif;
                dividen -= dif;
            }else{
                divsor = ans, dividen = 1;
                divsor -= dif;
                dividen += dif;
            }
            printf("TERM %d IS %d/%d\n",n,divsor,dividen);
        }
    }
    return 0;
}
