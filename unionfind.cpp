public class UnionFind {
  
public:
  UnionFind( int n ){
    
    fa.resize( n );
    for( int i = 0; i < n; ++ i )
      fa[i] = -1;
  }
  
  int find( int u ){
    int s = u;
    for( s = u; fa[s] >= 0; s = fa[s] ) ;
    while( s != u ){
      int tmp = fa[u];
      fa[u] = s;
      u = tmp;
    }
    return s;
  }
  
  int unionset( int a, int b ){
    int fa1 = find( a ), fa2 = find(b);
    int tmp = fa[fa1] + fa[fa2];
    if( fa[fa1] > fa[fa2] ){
      fa[fa1] = fa2;
      fa[fa2] = tmp;
    } else {
      fa[fa1] = tmp;
      fa[fa2] = fa1;
    }
  }
  
  private:
    vector<int> fa;
}
