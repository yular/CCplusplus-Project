/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
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
const int N = 10005;
const int M = 210000;
const long long MOD = 1000000007;
const double eps = 1e-10;

struct Girl
{
    int id;
    long long words;
}que[N];
int rear,fnt;
char t[15];

int find(int u){
    for (int i = 0; i < rear; ++ i) {
        if (que[i].id == u) {
            return i;
        }
    }
    return -1;
}

void moveToTop(int x){
    int topu = que[fnt].id;
    Girl tmp = que[x];
    for (int i = x; i > 0; -- i) {
        que[i] = que[i - 1];
        if (que[i].id == topu) {
            fnt = i;
        }
    }
    que[0] = tmp;
    if (que[0].id == topu) {
        fnt = 0;
    }
}

int main()
{
    int T;
    int op, id;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&op);
        rear = 0;
        fnt = -1;
        for (int oi = 1; oi <= op; ++ oi) {
            scanf("%s",t);
            printf("Operation #%d: ",oi);
            if (strcmp(t, "Add") == 0) {
                scanf("%d",&id);
                if (find(id) >= 0) {
                    printf("same priority.\n");
                    continue;
                }
                que[rear].id = id;
                que[rear].words = 0;
                ++ rear;
                printf("success.\n");
            }else if (strcmp(t,"Close")==0){
                scanf("%d",&id);
                int pl = find(id);
                if (pl >= 0) {
                    printf("close %d with %lld.\n",id,que[pl].words);
                    for (int i = pl; i < rear; ++ i) {
                        que[i] = que[i + 1];
                    }
                    -- rear;
                    if (pl == fnt) {
                        fnt = -1;
                    } else if (pl < fnt){
                        -- fnt;
                    }
                } else {
                    printf("invalid priority.\n");
                }
            }else if (strcmp(t,"Chat")==0){
                scanf("%d",&id);
                if(rear == 0){
                    printf("empty.\n");
                    continue;
                }
                if(fnt >= 0)
                    que[fnt].words+=id;
                else
                    que[0].words+=id;
                printf("success.\n");
            }else if (strcmp(t,"Top") == 0){
                scanf("%d",&id);
                int pl=find(id);
                if(pl >= 0){
                    printf("success.\n");
                    fnt = pl;
                }
                else
                    printf("invalid priority.\n");
            }else if(strcmp(t,"Untop")==0){
                if(fnt >= 0){
                    printf("success.\n");
                    fnt = -1;
                }
                else
                    printf("no such person.\n");
            }else if(strcmp(t,"Rotate")==0){
                scanf("%d",&id);
                if(id <= rear){
                    printf("success.\n");
                    moveToTop(id-1);
                }
                else
                    printf("out of range.\n");
            }else if(strcmp(t,"Choose")==0){
                scanf("%d",&id);
                int pl = find(id);
                if(pl >= 0){
                    printf("success.\n");
                    moveToTop(pl);
                }
                else{
                    printf("invalid priority.\n");
                }
            }else if(strcmp(t,"Prior")==0){
                if(rear == 0){
                    printf("empty.\n");
                    continue;
                }
                int maxid=0;
                for(int i=1;i < rear; ++ i)
                    if(que[i].id > que[maxid].id)
                        maxid=i;
                printf("success.\n");
                moveToTop(maxid);
            }
        }
        if(fnt >= 0 && que[fnt].words>0){
            printf("Bye %d: %lld\n",que[fnt].id,que[fnt].words);
            que[fnt].words=0;
        }
        for(int i=0;i < rear;i++){
            if(que[i].words>0)
                printf("Bye %d: %lld\n",que[i].id,que[i].words);
        }
    }
    return 0;
}
