/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(lgn)
*/
#include <stdio.h>
int a, b;

int gcd(int a, int b){
    return b == 0? a : gcd(b, a%b);
}

int main(){
    int T;
    scanf("%d",&T);
    while ( T -- ) {
        scanf("%d%d",&a,&b);
        if (a == 0 || b == 1) {
            printf("%d\n",b);
            continue;
        }
        if (a == 1 || b == 0) {
            printf("%d\n",a);
            continue;
        }
        printf("%d\n",gcd(a, b));
    }
    return 0;
}
