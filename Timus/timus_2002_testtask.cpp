/*
*
* Tag: Implementation
* Time: O(1)
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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 10050;
const int M = 10000100;
const long long MOD = 495;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
const int MAX_VAL = 800*1000;
unordered_map<string, string> userdb;
unordered_set<string> loginsession;
string op, user, pwd;

int main(){
    int T;
    cin>>T;
    userdb.clear();
    loginsession.clear();
    while (T --) {
        cin>>op>>user;
        if (op == "register") {
            cin>>pwd;
            if (userdb.count(user)) {
                cout<<"fail: user already exists"<<endl;
            } else {
                userdb[user] = pwd;
                cout<<"success: new user added"<<endl;
            }
        } else if (op == "login") {
            cin>>pwd;
            if (userdb.count(user)) {
                if (userdb[user] != pwd) {
                    cout<<"fail: incorrect password"<<endl;
                } else if (loginsession.count(user)) {
                    cout<<"fail: already logged in"<<endl;
                } else {
                    cout<<"success: user logged in"<<endl;
                    loginsession.insert(user);
                }
            } else {
                cout<<"fail: no such user"<<endl;
            }
        } else {
            if (userdb.count(user)) {
                if (loginsession.count(user)) {
                    cout<<"success: user logged out"<<endl;
                    loginsession.erase(user);
                } else {
                    cout<<"fail: already logged out"<<endl;
                }
            } else {
                cout<<"fail: no such user"<<endl;
            }
        }
    }
    return 0;
}
