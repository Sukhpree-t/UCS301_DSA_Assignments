//4. Write a program to implement kruskal's minimum spanning tree algorithm.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
  int u, v, w;
};

int findParent(int node, vector<int> &parent){
  if(node == parent[node]){
    return node;
  }
  return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> & rank){
  int pu = findParent(u, parent);
  int pv = findParent(v, parent);

  if(pu == pv){
    return;
  }
  if(rank[pu] < rank[pv]){
    parent[pu] = pv;
  }
  else if(rank[pu] > rank[pv]){
    parent[pv] = pu;
  }
  else{
    parent[pv] = pu;
    rank[pu]++;
  }
}

int spanningTree(int n, vector<Edge> & edges){
  sort(edges.begin(), edges.end(), [](Edge a, Edge b){
    return a.w < b.w;
  });
  vector<int> parent(n);
  vector<int> rank(n,0);
  for(int i=0; i<n; i++){
    parent[i] = i;
  }
  int totalWeight = 0;
  vector<Edge> mst;
  for(auto e : edges){
    int pu = findParent(e.u, parent);
    int pv = findParent(e.v, parent);
    if(pu != pv){
      mst.push_back(e);
      unionSet(e.u, e.v, parent, rank);
      totalWeight += e.w;
    }
  }
  cout<<"Edges in mst : "<<endl;
  for(auto e : mst){
    cout<<e.u<<" - "<<e.v<<" weight : "<<e.w<<endl;
  }
  return totalWeight;
}

int main(){
  int n, m;
  cout<<"Enter number of nodes : ";
  cin>>n;
  cout<<"Enter number of edges :";
  cin>>m;
  vector<Edge> edges(m);
  cout<<"Enter edges (u v weight) : "<<endl;
  for(int i=0; i<m; i++){
    cin>>edges[i].u>>edges[i].v>>edges[i].w;
  }
  int weight = spanningTree(n, edges);
  cout<<"Total weight of minimum spannig tree : "<<weight;


  return 0;
}