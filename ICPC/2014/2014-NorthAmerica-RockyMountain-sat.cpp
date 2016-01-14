/*
*
* WA
*
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 30;
const int M = 1011;
//const int INF = 1<<29;
int n, m;
bool issat;
int assarr[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304};
int clause[M][N], var[N], varcnt, claucnt;
bool negchk[M][N], excludeset[N];
int combres;
char clausestatm[M];

void init(){
    issat = true;
    varcnt = claucnt = 0;
    combres = 0;
    
    memset(negchk, 0, sizeof(negchk));
    memset(excludeset, 0, sizeof(excludeset));
    memset(clause, 0, sizeof(clause));
    
    for (int i = 0; i < m;  ++ i) {
        gets(clausestatm);
    //    getchar();
    //    puts(clausestatm);
        clause[claucnt][0] = 0;
        int tmpvarcnt = 0;
        bool isneg = false;
        int varnum = 0;
        for (int j = 0; clausestatm[j]; ++ j) {
            isneg = false;
            varnum = 0;
            while (clausestatm[j] && clausestatm[j] != ' ') {
                if (clausestatm[j] == '~') {
                    isneg = true;
                    ++ j;
                }else if (clausestatm[j] == 'X') {
                    ++ j;
                    continue;
                }else {
                    while (clausestatm[j] >= '0' && clausestatm[j] <= '9' && clausestatm[j]) {
                        varnum = varnum*10 + (clausestatm[j] - '0');
                        ++ j;
                    }
                }
            }
            ++ tmpvarcnt;
            ++ clause[claucnt][0];
            clause[claucnt][clause[claucnt][0]] = varnum;
            negchk[claucnt][clause[claucnt][0]] = isneg;
     //       printf("%d(%d) ",varnum,isneg);
            while (clausestatm[j] && (clausestatm[j] == ' ' || clausestatm[j] == 'v')) {
                ++ j;
            }
            -- j;
          //  printf("j = %d\n",j);
        }
//        printf(" -> %d\n",tmpvarcnt);
        if (tmpvarcnt > 1) {
            ++ claucnt;
        } else {
            if (!excludeset[varnum]) {
                excludeset[varnum] = 1;
                if (!isneg) {
                    combres |= assarr[varnum];
                }
            } else {
                if ((!isneg && !(combres&assarr[varnum])) || (isneg && (combres&assarr[varnum]))) {
                    issat = false;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; ++ i) {
        if (!excludeset[i]) {
            var[++ varcnt] = i;
        }
    }
    
 /*   for (int i = 0; i < claucnt; ++ i) {
        for (int j = 1; j <= clause[i][0]; ++ j) {
            printf("%d(%d) ",clause[i][j],negchk[i][j]);
        }
        puts("");
    }
    printf("%d\n",combres); */
}

/*
void ninit(){
    int a = 1;
    for (int i = 0; i <= 22; ++ i) {
        printf("%d,",a);
        a<<=1;
    }
}
*/

void dfs(int depth){
    if (depth > varcnt) {
  //      printf("combres = %d\n",combres);
        for (int i = 0; i < claucnt; ++ i) {
            int res = 0;
            for (int j = 1; j <= clause[i][clause[i][0]]; ++ j) {
                int tmpres = (combres&assarr[clause[i][j]]);
                if (negchk[i][j]) {
                    if (tmpres) {
                        tmpres = 0;
                    } else {
                        tmpres = 1;
                    }
                }
            //    printf("combres = %d %d(%d) assarr = %d tmpres = %d\n",combres, clause[i][j],negchk[i][j],assarr[clause[i][j]],tmpres);
                res |= tmpres;
                if (res) {
                    break;
                }
            }
            if (!res) {
      //          puts("");
                return ;
            }
        }
 //       printf(" res = %d\n",combres);
        issat = true;
        return ;
    }
    
    dfs(depth + 1);
    if (issat) {
        return ;
    }
    combres = combres^assarr[var[depth]];
    dfs(depth + 1);
    combres = combres^assarr[var[depth]];
}

int main() {
/*
 
 PROG:vans
 
 ID:ybcabcd
 
 LANG:C++
 
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <utility>
#include <bitset>
#include <vector>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 30;
const int M = 1011;
//const int INF = 1<<29;
int n, m;
bool issat;
int assarr[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304};
int clause[M][N], var[N], varcnt, claucnt;
bool negchk[M][N], excludeset[N];
int combres;
char clausestatm[M];

void init(){
    issat = true;
    varcnt = claucnt = 0;
    combres = 0;
    
    memset(negchk, 0, sizeof(negchk));
    memset(excludeset, 0, sizeof(excludeset));
    memset(clause, 0, sizeof(clause));
    
    for (int i = 0; i < m;  ++ i) {
        gets(clausestatm);
    //    getchar();
    //    puts(clausestatm);
        clause[claucnt][0] = 0;
        int tmpvarcnt = 0;
        bool isneg = false;
        int varnum = 0;
        for (int j = 0; clausestatm[j]; ++ j) {
            isneg = false;
            varnum = 0;
            while (clausestatm[j] && clausestatm[j] != ' ') {
                if (clausestatm[j] == '~') {
                    isneg = true;
                    ++ j;
                }else if (clausestatm[j] == 'X') {
                    ++ j;
                    continue;
                }else {
                    while (clausestatm[j] >= '0' && clausestatm[j] <= '9' && clausestatm[j]) {
                        varnum = varnum*10 + (clausestatm[j] - '0');
                        ++ j;
                    }
                }
            }
            ++ tmpvarcnt;
            ++ clause[claucnt][0];
            clause[claucnt][clause[claucnt][0]] = varnum;
            negchk[claucnt][clause[claucnt][0]] = isneg;
     //       printf("%d(%d) ",varnum,isneg);
            while (clausestatm[j] && (clausestatm[j] == ' ' || clausestatm[j] == 'v')) {
                ++ j;
            }
            -- j;
          //  printf("j = %d\n",j);
        }
//        printf(" -> %d\n",tmpvarcnt);
        if (tmpvarcnt > 1) {
            ++ claucnt;
        } else {
            if (!excludeset[varnum]) {
                excludeset[varnum] = 1;
                if (!isneg) {
                    combres |= assarr[varnum];
                }
            } else {
                if ((!isneg && !(combres&assarr[varnum])) || (isneg && (combres&assarr[varnum]))) {
                    issat = false;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; ++ i) {
        if (!excludeset[i]) {
            var[++ varcnt] = i;
        }
    }
    
 /*   for (int i = 0; i < claucnt; ++ i) {
        for (int j = 1; j <= clause[i][0]; ++ j) {
            printf("%d(%d) ",clause[i][j],negchk[i][j]);
        }
        puts("");
    }
    printf("%d\n",combres); */
}

/*
void ninit(){
    int a = 1;
    for (int i = 0; i <= 22; ++ i) {
        printf("%d,",a);
        a<<=1;
    }
}
*/

void dfs(int depth){
    if (depth > varcnt) {
  //      printf("combres = %d\n",combres);
        for (int i = 0; i < claucnt; ++ i) {
            int res = 0;
            for (int j = 1; j <= clause[i][clause[i][0]]; ++ j) {
                int tmpres = (combres&assarr[clause[i][j]]);
                if (negchk[i][j]) {
                    if (tmpres) {
                        tmpres = 0;
                    } else {
                        tmpres = 1;
                    }
                }
            //    printf("combres = %d %d(%d) assarr = %d tmpres = %d\n",combres, clause[i][j],negchk[i][j],assarr[clause[i][j]],tmpres);
                res |= tmpres;
                if (res) {
                    break;
                }
            }
            if (!res) {
      //          puts("");
                return ;
            }
        }
 //       printf(" res = %d\n",combres);
        issat = true;
        return ;
    }
    
    dfs(depth + 1);
    if (issat) {
        return ;
    }
    combres = combres^assarr[var[depth]];
    dfs(depth + 1);
    combres = combres^assarr[var[depth]];
}

int main() {

    //    freopen("/Users/baiyang/Project/CCPP/USACO/USACO/text_editor.txt", "r", stdin);
    //    freopen("/Users/baiyang/Project/CCPP/USACO/USACO/text_editor.out", "w", stdout);
//    ninit();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
    //    printf("%d %d\n",n,m);
        getchar();
        init();
        if (!issat) {
            puts("unsatisfiable");
            continue;
        }
        issat = false;
        dfs(1);
        if (issat) {
            puts("satisfiable");
        } else {
            puts("unsatisfiable");
        }
    }
    return 0;
    
}

//    ninit();
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&n,&m);
    //    printf("%d %d\n",n,m);
        getchar();
        init();
        if (!issat) {
            puts("unsatisfiable");
            continue;
        }
        issat = false;
        dfs(1);
        if (issat) {
            puts("satisfiable");
        } else {
            puts("unsatisfiable");
        }
    }
    return 0;
    
}
