/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 310;
const int M = 101010;
const double eps = 1e-10;
int a, b;

int main() {
    scanf("%d%d",&a,&b);
    int sum = 0;
    for(int i = a; i <= b; ++ i){
    	sum += i*i;
    }
    printf("%d\n",sum);
    return 0;
}
