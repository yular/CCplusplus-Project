/*
*
* Tag: Data Structure (Binary Index Tree)
* Time: O(nlgn)
* Space: O(n)
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
const int M = 15300;
const int N = 32020;
const double eps = 1e-8;
const double dinf = 1e15;
const double PI = acos(-1.0);
const int MOD = 100000007;
int n, bnd;
int ans[M], tree[N];
pair<int,int> stars[M];
set<int> st;
map<int,int> mp;

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int lowbit(int x){
    return x&-x;
}

int sum(int val){
    int res = 0;
    for(int i = val; i > 0; i -= lowbit(i))
        res += tree[i];
    return res;
}

void update(int val){
    for(int i = val; i <= bnd; i += lowbit(i))
        ++ tree[i];
}

int main(){
 //   freopen("out.txt","w",stdout);
    scanf("%d",&n);
    bnd = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d%d",&stars[i].first,&stars[i].second);
        st.insert(stars[i].first);
        st.insert(stars[i].second);
    }
    int id = 1;
    set<int>::iterator it = st.begin();
    for(; it != st.end(); ++ it, ++ id){
        mp[*it] = id;
    }
    bnd = id;
    for(int i = 0; i < n; ++ i){
        stars[i].first = mp[stars[i].first];
        stars[i].second = mp[stars[i].second];
    }
    memset(ans, 0, sizeof(ans));
    memset(tree, 0, sizeof(tree));
    sort(stars, stars + n, cmp);
    for(int i = 0; i < n; ++ i){
        int id = sum(stars[i].first);
        ++ ans[id];
        update(stars[i].first);
    }
    for(int i = 0; i < n; ++ i)
        printf("%d\n",ans[i]);
    return 0;
}
