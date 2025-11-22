//2. Write a program to implement breadth first search algorithm.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> adj, int v, int n){
  vector<int> vis(n,0);
  queue<int> q;
  q.push(v);
  vis[v] = 1;
  while(!q.empty()){
    int idx = q.front();
    q.pop();
    cout<<idx<<" ";
    for(auto i : adj[idx]){
      if(vis[i] == 0){
        vis[i] = 1;
        q.push(i);
      }
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
  bfs(adj,0,n);
  
  return 0;
}