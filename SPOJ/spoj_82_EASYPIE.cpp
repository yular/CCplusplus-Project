/*
 *
 * Tag: Implementation
 * Time: O(nlgn)
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
const int N = 20;
const int M = 120;
const int NN = 3000;
const double eps = 1e-10;
struct problems{
    int actimes;
    int submittimes;
    int tottime;
    unordered_set<string> team;
}p[N];
struct teams{
    bool ac[N];
    int subtimes[N];
}t[M];
struct submissions{
    int time;
    string team;
    string problemId;
    string res;
    bool operator < (const submissions a) const {
        return time < a.time;
    }
}s[NN];
unordered_map<string, int> dict;
int n;

void init(){
    for (int i = 0; i < N; ++ i) {
        p[i].team.clear();
        p[i].actimes = 0;
        p[i].tottime = 0;
        p[i].submittimes = 0;
    }
    for (int i = 0; i < M; ++ i) {
        memset(t[i].ac, 0, sizeof(t[i].ac));
        memset(t[i].subtimes, 0, sizeof(t[i].subtimes));
    }
    dict.clear();
}

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        init();
        int id = 0;
        for (int i = 0; i < n; ++ i) {
            char name[N], prob[N], res[N];
            scanf("%d%s%s%s",&s[i].time,name,prob,res);
            s[i].team = string(name);
            s[i].problemId = string(prob);
            s[i].res = string(res);
            if (dict.find(s[i].team) == dict.end()) {
                dict[s[i].team] = id ++;
            }
        }
        sort(s, s + n);
        for (int i = 0; i < n; ++ i) {
            if (s[i].res == "A") {
                int pid = s[i].problemId[0] - 'A', tid = dict[s[i].team];
                if (p[pid].team.find(s[i].team) == p[id].team.end()) {
                    ++ p[pid].actimes;
                    p[pid].tottime += s[i].time;
                    p[pid].submittimes += (t[tid].subtimes[pid] + 1);
                    p[pid].team.insert(s[i].team);
                    t[tid].ac[id] = 1;
                }
            } else {
                int tid = dict[s[i].team], pid = s[i].problemId[0] - 'A';
                if (!t[tid].ac[pid]) {
                    ++ t[tid].subtimes[pid];
                }
            }
        }
        for (int i = 0; i < 9; ++ i) {
            char id = 'A' + i;
            printf("%c %d", id,p[i].actimes);
            if (p[i].actimes) {
                printf(" %.2lf %.2lf",(double)p[i].submittimes/(double)p[i].actimes,(double)p[i].tottime/(double)p[i].actimes);
            }
            puts("");
        }
    }
    return 0;
}
