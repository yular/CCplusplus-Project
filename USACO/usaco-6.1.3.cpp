/*
*
* Tag: Bit Manipulation (Bit Tree)
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
const int N = 750000;
const int M = 22;
const int LIM = 1000000000;
const double eps=1e-8;
const int maxn=750000;
const int maxm=22;
int tree[maxn][2],a[maxm],num[maxn],sum[maxn],ans_start,ans_end,ans,i,n,t,cnt,f,x,now,j;

void insert(int k,int step)
{
  if (step==maxm) {num[k]=i;return;}
  int t=a[step];
  if (tree[k][t]>0)
    insert(tree[k][t],step+1);
  else {
      tree[k][t]=++cnt;
      insert(cnt,step+1);
  }
}
int find(int k,int step)
{
  int t=a[step];
  if (tree[k][t^1]>0) return find(tree[k][t^1],step+1);
  if (tree[k][t]>0) return find(tree[k][t],step+1);
  return num[k];
}
int main()
{
  freopen("cowxor.in","r",stdin);
  freopen("cowxor.out","w",stdout);
  scanf("%d",&n);cnt=0;sum[0]=0;
  for (i=1;i<=n;i++)
  {
    scanf("%d",&x);
    now=0;
    sum[i]=sum[i-1]^x;
    x=sum[i];
    while (now<maxm-1){
        a[++now]=x%2;
        x/=2;
    }
    for (j=1;j<=now/2;j++) {
        t=a[j];a[j]=a[now-j+1];a[now-j+1]=t;
    }
    f=find(0,1);
    if ((sum[i]^sum[f])>ans) {
        ans_start=f+1;ans_end=i;ans=sum[i]^sum[f];
    }
    insert(0,1);
  }
  if (ans==0) printf("0 1 1\n");
  else printf("%d %d %d\n",ans,ans_start,ans_end);
  return 0;
}
