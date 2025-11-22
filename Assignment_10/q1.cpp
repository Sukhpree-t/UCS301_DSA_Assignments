//1. Program: Graph representation (Adjacency Matrix/List) + Basic operations

#include<iostream>
#include<vector>
#include<limits>
#include<string>
using namespace std;

class Graph{
  vector<vector<int>> adjmat;
  vector<vector<int>> adjlist;
  vector<int> indegree;
  vector<int> outdegree;
  int n;
public:
  Graph(){
    // Use robust input for number of nodes
    n = readInt("Enter number of nodes: ");
    while(n <= 0) {
      cout << "Number of nodes must be positive.\n";
      n = readInt("Enter number of nodes: ");
    }
    adjmat.resize(n, vector<int>(n, 0));
    adjlist.resize(n);
    indegree.resize(n, 0);
    outdegree.resize(n, 0);
  }

  // Helper to read an integer robustly from stdin
  static int readInt(const string &prompt) {
    int x;
    while (true) {
      cout << prompt;
      if (cin >> x) {
        return x;
      }
      cout << "Invalid input. Please enter an integer.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  void addEdge(){
    int u = readInt("Enter source vertex (u): ");
    int v = readInt("Enter destination vertex (v): ");
    if(u < 0 || v < 0 || u >= n || v >= n){
      cout << "Invalid nodes!\n";
      return;
    }
    // Avoid duplicate entries in matrix
    if(adjmat[u][v] == 0){
      adjmat[u][v] = 1;
      adjlist[u].push_back(v);
      outdegree[u]++;
      indegree[v]++;
    }
  }
  void printAdjMatrix(){
    cout << "\nAdjacency Matrix:\n";
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << adjmat[i][j] << " ";
      }
      cout << endl;
    }
  }

  void printAdjList(){
    cout << "\nAdjacency List:\n";
    for(int i = 0; i < n; i++){
      cout << i << " -> ";
      for(auto v : adjlist[i]){
        cout << v << " ";
      }
      cout << endl;
    }
  }
  void printDegrees(){
    int v = readInt("Enter vertex : ");
    if(v < 0 || v >= n){
      cout << "Invalid vertex!\n";
      return;
    }
    cout << "In-degree of " << v << " = " << indegree[v] << endl;
    cout << "Out-degree of " << v << " = " << outdegree[v] << endl;
  }

  void printAdjacent(){
    int v = readInt("Enter vertex : ");
    if(v < 0 || v >= n){
      cout << "Invalid vertex!\n";
      return;
    }
    cout << "Adjacent vertices of " << v << ": ";
    for(auto x : adjlist[v]){
      cout << x << " ";
    }
    cout << endl;
  }
};

int main(){
  Graph g;
    
  int choice;
  do{
    cout << "\n--- MENU ---\n"
         << "1. Add Edge\n"
         << "2. Print Adjacency Matrix\n"
         << "3. Print Adjacency List\n"
         << "4. Degree of a Vertex\n"
         << "5. Adjacent Vertices\n"
         << "6. Exit\n";
    choice = Graph::readInt("Enter choice: ");
    switch(choice){
      case 1 : g.addEdge();
      break;
      case 2 : g.printAdjMatrix();
      break;
      case 3 : g.printAdjList();
      break;
      case 4 : g.printDegrees();
      break;
      case 5 : g.printAdjacent();
      break;
      case 6 : cout<<"Exiting programme\n";
      break;
      default : 
        cout << "Invalid choice!\n";
    }
  }while(choice != 6);

    return 0;
}
