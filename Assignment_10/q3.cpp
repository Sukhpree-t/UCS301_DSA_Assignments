//3. Write a program to implement depth first search algorithm.

#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj,vector<int> &vis){
  vis[node] = 1;
  cout<<node<<" ";
  for(auto it : adj[node]){
    if(vis[it] == 0){
      dfs(it, adj, vis);
    }
  }
}

int main(){
  int n, m;
  cout<<"Enter number of nodes : ";
  cin>>n;
  cout<<"Enter number of edges : ";
  cin>>m;
  vector<vector<int>> adj(n, vector<int> ());
  cout<<"Enter edge (u v)";
  for(int i=0; i<m; i++){
    int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(n,0);
  dfs(0, adj,vis);
  
  return 0;
}