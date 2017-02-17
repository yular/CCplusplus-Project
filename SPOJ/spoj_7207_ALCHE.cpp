/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);


int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;  
}

double I, W;

int main() {
  while (cin >> I >> W && I != -1.0) {
    cout << (cmp(I/W, 1000.0/37.0) == 0 ? "Y" : "N") << endl; 
  }
  return 0;
}
