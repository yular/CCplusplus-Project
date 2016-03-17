#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
#define T int
#define NUM int
#define INF 1<<29
#define ERROR INT_MAX

class Floyd {
public:
    vector<vector<T>> graph, dp;
    NUM num_node, num_edge;
    
    //Initialization: set the total number of nodes and total number of edges
    Floyd(NUM nodes, NUM edges){
        num_node = nodes;
        num_edge = edges;
        graph.resize(num_node + 1);
        for (int i = 0; i <= num_node; ++ i) {
            vector<T> new_vec(num_node + 1);
            graph[i] = new_vec;
        }
        for (int i = 0; i <= num_node; ++ i) {
            for (int j = 0; j <= num_node; ++ j) {
                if (i == j) {
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = INF;
                }
            }
        }
        dp = graph;
    }
    
    void setEdgeWeight(NUM u, NUM v, T w){
        graph[u][v] = min(graph[u][v], w);
    }
    
    T getEdgeWeight(NUM u, NUM v){
        if (u < 0 || u > num_node || v < 0 || v > num_node) {
            return ERROR;
        }
        return graph[u][v];
    }
    
    T getShortestPath(NUM u, NUM v){
        if (u < 0 || u > num_node || v < 0 || v > num_node) {
            return ERROR;
        }
        return dp[u][v];
    }
    
    void FloydShortestPath(){
        for (int k = 0; k <= num_node; ++ k) {
            for (int i = 0; i <= num_node; ++ i) {
                for (int j = 0; j <= num_node; ++ j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
    
};

int main() {
    
    return 0;
}
