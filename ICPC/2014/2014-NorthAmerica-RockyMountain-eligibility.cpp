/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100;
const int M = 1001000;
char name[N];
int y[2], m[2],d[2],c;

int check(){
    if (y[0] >= 2010)
        return 0;
    if (y[1] >= 1991)
        return 0;
    if (c >= 41)
        return 1;
    return 2;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%s %d/%d/%d %d/%d/%d %d",name, &y[0], &m[0], &d[0], &y[1], &m[1], &d[1], &c);
        int ans = check();
        if(ans == 0)
            printf("%s eligible\n",name);
        else if(ans == 1)
            printf("%s ineligible\n", name);
        else
            printf("%s coach petitions\n", name);
    }
    return 0;
}
