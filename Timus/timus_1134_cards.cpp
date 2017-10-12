/*
*
* Tag: Greedy
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
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
const int N = 1300;
const int M =24005;
const long long MOD = 26;
const long long INF = 4e11;
const double PI = acos(-1.0);
const double DOUBLEMAX = 10000000001;
const double eps = 1e-10;
int n, m, cards[N];
bool find_card[N];

void init() {
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d", &cards[i]);
    }
    memset(find_card, 0, sizeof(find_card));
}

void sort_cards(){
    sort(cards, cards + m);
}


bool is_out_of_bound(int v){
    return v < 0 || v > n;
}

bool is_seq_valid() {
    for (int i = 0; i < m; ++ i ) {
        int card_val = cards[i];
        if (is_out_of_bound(card_val)) {
            return false;
        }
        if (card_val > 0 && !find_card[card_val]) {
            find_card[card_val] = true;
        } else if(!find_card[card_val + 1]) {
            find_card[card_val + 1] = true;
            if (is_out_of_bound(card_val + 1)) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

void print_seq_exist_result(bool seq_exist){
    if (seq_exist) {
        puts("YES");
    } else {
        puts("NO");
    }
}

int main(){
    init();
    
    sort_cards();
    
    bool seq_exist = is_seq_valid();
   
    print_seq_exist_result(seq_exist);
    return 0;
}
