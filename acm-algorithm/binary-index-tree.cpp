#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define T int

/*
* Another name of this data structure is Fenwick tree
*/
class binaryindextree {
public:
	vector<T> bidxtree;
	int bound;

	//Initialization: set the maximum number of elements of binary index tree.
	binaryindextree(int bnd){
		bound = bnd;
		bidxtree.resize(bound + 1);
		for(int i = 0; i <= bound; ++ i){
			bidxtree[i] = 0;
		}
	}

	//Update the sum of range from start index to bound index
	void update(int start, T val){
		for(int i = start; i <= bound; i += lowbit(i)){
			bidxtree[i] += val;
		}
	}

	//Calculate the sum of range from 1 index to bnd index
	T sumup(int bnd){
		T res = 0;
		for(int i = bnd; i > 0; i -= lowbit(i)){
			res += bidxtree[i];
		}
		return res;
	}

private:
	//The step of iteration
	int lowbit(int x){
		return x&-x;
	}

};

int main(){
	return 0;
}
