/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int N = 1000200;
const int M = 300;
const long long MOD = 1000000007;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
int n;

int cmp(const void *a, const void *b){
    return ( *(int*)a - *(int*)b);
}

int main(){
    int T;
    int arr[N];
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&arr[i]);
        }
        qsort (arr, n, sizeof(int), cmp);
        for (int i = 0; i < n; ++ i) {
            printf("%d\n",arr[i]);
        }
        puts("");
    }
    return 0;
}
