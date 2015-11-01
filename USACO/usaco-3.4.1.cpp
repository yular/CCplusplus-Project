/*
*
* Tag: DFS
* Time: O(n^2) (using adjacent list the time complexity can be reduced to O(n))
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
const int N = 30;
const int M = 1010;
string inorder, preorder;
int mp[N][N];
int root, idx;

void build(int sta, int lst, int parent, int lr){
    for(int i = sta; i <= lst; ++ i){
        if(inorder[i] == preorder[idx]){
            //cout<<inorder[i]<<endl;
            if(parent == -1){
                root = preorder[idx] - 'A';
                ++ idx;
                build(sta, i - 1, root, 1);
                build(i + 1, lst, root, 2);
                break;
            }else{
                int chd = preorder[idx] - 'A';
                ++ idx;
                mp[parent][chd] = lr;
                build(sta, i - 1, chd, 1);
                build(i + 1, lst, chd, 2);
                break;
            }
        }
    }
}

void dfs(int root){
    int chd[2] = {-1, -1};
    for(int i = 0; i < 26; ++ i){
        if(mp[root][i] == 1)
            chd[0] = i;
        else if(mp[root][i] == 2)
            chd[1] = i;
    }
    if(chd[0] != -1)
        dfs(chd[0]);
    if(chd[1] != -1)
        dfs(chd[1]);
    char ch=(char)('A'+root);
    cout<<ch;
}

int main(){
    freopen("heritage.in","r",stdin);
    freopen("heritage.out","w",stdout);
    cin>>inorder>>preorder;
    memset(mp, 0, sizeof(mp));
    root = -1;
    build(0, inorder.size() - 1, -1, -1);
    dfs(root);
    cout<<endl;
    return 0;
}
