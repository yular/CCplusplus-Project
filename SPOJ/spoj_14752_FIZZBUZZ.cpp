#include <cstdio>
using namespace std;
int n;int main(){int T;scanf("%d",&T);while(T --){scanf("%d",&n);if(n%5 == 0 && n%7 == 0)puts("fizzbuzz");else if (n%5 == 0)puts("fizz");else if (n%7 == 0)puts("buzz");else printf("%d\n",n);}return 0;}
