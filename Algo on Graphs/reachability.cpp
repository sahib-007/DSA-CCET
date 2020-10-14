#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using std::vector;
using std::pair;

vector<int> vis;

bool dfs(vector<vector<int>> &adj, int x, int y){
    vis[x] = 1;
    if(x == y) return true;
  
    for( auto v:adj[x]){
        if( !vis[v] ){
            if(dfs( adj, v, y)){
              return true;
            }
        }
    }
    return false;
}
int reach(vector<vector<int> > &adj, int x, int y) {

  return dfs( adj, x, y);

}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  vis = vector<int>(n,0);
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
