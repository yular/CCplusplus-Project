/*
*
* Tag: Implementation
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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 20;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
string contestName, contestDate, problemId, submitResult;
int p, s;
int problemState[N];

void printNEmptySpaces(int n){
    for (int i = 0; i < n; ++ i) {
        cout<<" ";
    }
}

void printBounder(){
    cout<<"+------------------------------+--------+-------------+"<<endl;
}

void printTitle(){
    cout<<"|Contest name                  |Date    |ABCDEFGHIJKLM|"<<endl;
}

int getProblemIntId(string problemId){
    return problemId[0] - 'A';
}

bool isProblemStatusAccepted(int problemId, string submitResult){
    return problemState[problemId] == 2 || submitResult == "Accepted";
}

void printLeftRightBounder(){
    cout<<"|";
}

void printContestName(){
    printLeftRightBounder();
    cout<<contestName;
    int contestNameTailingSpaces = 30 - (int)contestName.size();
    printNEmptySpaces(contestNameTailingSpaces);
    printLeftRightBounder();
}

void printContestDate(){
    cout<<contestDate;
    printLeftRightBounder();
}

char getProblemSubmittedStatus(int status){
    switch (status) {
        case 0:
            return ' ';
            break;
        case 1:
            return '.';
            break;
        case 2:
            return 'o';
            break;
        default:
            return 'x';
            break;
    }
}

void printProblemSubmittedResult(){
    for (int i = 0; i < 13; ++ i) {
        cout<<getProblemSubmittedStatus(problemState[i]);
    }
    printLeftRightBounder();
    cout<<endl;
}

int main(){
    int T;
    cin>>T;getchar();
    
    printBounder();
    printTitle();
    printBounder();
    
    while (T --) {
        memset(problemState, 0, sizeof(problemState));
        getline(cin, contestName);
        cin>>contestDate;
        cin>>p>>s;getchar();
        
        for (int i = 0; i < p; ++ i) {
            problemState[i] = 1;
        }
        
        for (int i = 0; i < s; ++ i) {
            cin>>problemId;getchar();
            getline(cin, submitResult);
            int id = getProblemIntId(problemId);
            if (isProblemStatusAccepted(id, submitResult)) {
                problemState[id] = 2;
            } else {
                problemState[id] = 3;
            }
        }
        
        printContestName();
        printContestDate();
        printProblemSubmittedResult();
        printBounder();
        
    }
    return 0;
}
