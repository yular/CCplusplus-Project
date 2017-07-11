public class Floyd {
private:
  int numNode = 1105;
  vector<vector<int> > graph;
public:
  Floyd(int n){
    numNode = n;
    graph.resize(numNode);
    for(int i = 0; i < n; ++ i){
      vector<int> tmpgraph(n);
      graph[i] = tmpgraph;
    }
  }
  
  void buildGraph(int m, bool isDirective){
    for(int i = 0; i < m; ++ i){
      int u, v, w;
      scanf("%d%d%d",&u,&v,&w);
      graph[u][v] = w;
      if(isDirective)
        graph[v][u] = w;
    }
  }
  
  void floyd(){
    
    for(int k = 0; k < n; ++ k){
      for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }
    
  }
  
  int getDist(int s, int t){
    return graph[s][t];
  }
  
}
