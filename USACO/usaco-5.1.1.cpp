/*
*
* Tag: Covex Hull
* Time: O(n^2)
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
const int N = 10010;
const int M = 500;
const int LIM = 1000000000;
const double eps=1e-8;
struct point{
	double x,y;
}points[N],stk[N];
int top, n;

double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double crossmulti(point p0,point p1,point p2){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

bool cmp(point p,point q){
	double k=crossmulti(points[0],p,q);
	if(k<-eps)
		return 0;
	else if(fabs(k)<eps && (dis(p,points[0])-dis(q,points[0]))>eps)
		return 0;
	else return 1;
}

void cover_hull(int n){

	double miny=points[0].y;
	int index=0;
	for(int i = 1; i < n; ++ i){
		if(points[i].y < miny){
			miny = points[i].y;
			index = i;
		}
		else if(fabs(points[i].y - miny) < eps && points[i].x<points[index].x){
			index = i;
		}
	}
	point temp;
	temp = points[index];
	points[index] = points[0];
	points[0] = temp;
	sort(points+1,points+n,cmp);
	stk[0]=points[n-1];
	stk[1]=points[0];
	top = 1;
	int k = 1;
	while(k <= n-1){
		double d=crossmulti(stk[top],stk[top-1],points[k]);
		if(d<=0){
			top++;
			stk[top] = points[k];
			k++;
		}
		else
            top--;
	}
}

int main(){
    freopen("fc.in","r",stdin);
    freopen("fc.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i)
        scanf("%lf%lf",&points[i].x,&points[i].y);
    cover_hull(n);
    double ans = 0;
    for(int i = 0; i < top; ++ i){
        ans += dis(stk[i], stk[(i + 1)%n]);
   //     printf("%.2lf %.2lf\n",points[i].);
    }
    printf("%.2lf\n",ans);
    return 0;
}
