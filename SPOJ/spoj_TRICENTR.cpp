/*
*
* Tag: Math
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
const int MOD = 100000007;
double a, b, c, da, db, dc, s, r, m;

int main(){
 //   freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%lf%lf%lf%lf", &a, &da, &db, &dc);
        s = 3.0*a*da/2.0;
		b = 2.0*s/3.0/db;
		c = 2.0*s/3.0/dc;
		r = a*b*c/4.0/s;
		m = 4.0*(r*r-(a*a+b*b+c*c)/9.0);
		m = (m<0.0) ? 0.0 : m;
		printf("%.3lf %.3lf\n", s, sqrt(m));
    }
    return 0;
}
