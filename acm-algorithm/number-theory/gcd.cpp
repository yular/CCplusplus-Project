#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define T int

class GCD {
private:
    T a, b;
public:
    GCD(){
        a = b = 1;
    }
    
    GCD(T a_val, T b_val){
        a = a_val;
        b = b_val;
    }
    
    T getGCD(T a, T b){
        return b == 0?a : getGCD(b, a%b);
    }
};
