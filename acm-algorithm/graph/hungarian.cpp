/*
*
* Tag: Graph
* Time: O(n^3) (or O(nm))
* Space: O(n^2)
*/
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define T int
#define NUM int

class Hungarian {
public:
    vector<vector<bool>> graph;
    vector<bool> vis;
    vector<T> result;
    NUM num_u_nodes, num_v_nodes;
    NUM ans;
    
    Hungarian(NUM u_nodes, NUM v_nodes){
        num_u_nodes = u_nodes;
        num_v_nodes = v_nodes;
        ans = 0;
        graph.resize(num_u_nodes + 1);
        for (int i = 0; i <= num_u_nodes; ++ i) {
            vector<bool> g_vec(num_v_nodes + 1);
            for (int j = 0; j <= num_v_nodes; ++ j) {
                g_vec[j] = false;
            }
            graph[i] = g_vec;
        }
        result.resize(num_v_nodes + 1);
        vis.resize(num_v_nodes + 1);
        for (int i = 0; i <= num_v_nodes; ++ i) {
            result[i] = 0;
            vis[i] = 0;
        }
        
    }
    
    void setEdge(int u, int v){
        graph[u][v] = true;
    }
    
    bool find(int u){
        for (int v = 1; v <= num_v_nodes; ++ v) {
            if (graph[u][v] && !vis[v]) {
                vis[v] = 1;
                if (result[v] == 0 || find(result[v])) {
                    result[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    
    int getMaxMatch(){
        for (int i = 1; i <= num_u_nodes; ++ i) {
            for (int j = 0; j <= num_v_nodes; ++ j) {
                vis[j] = 0;
            }
            if (find(i)) {
                ++ ans;
            }
        }
        return ans;
    }
    
};

int main() {
    return 0;
}
