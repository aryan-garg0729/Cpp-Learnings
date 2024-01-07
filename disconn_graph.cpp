#include<iostream>
using namespace std;
#include<queue>

//Depth First Search (DFS)
void printDFS(int** edges, int n, int sv, bool* visited){
  cout << sv << " ";
  visited[sv] = true;    // marking that element visited to avoid infinite loop
  for(int i=0; i<n; i++){
    if(i==sv){    //if an element is related to itself then it can form an infinite loop so to
      continue;  // avoid it we need this 'if' statement
    }
    if(edges[sv][i]==1){  //if(the connection exists)
      if(visited[i]){     //if(visited) then skip 
        continue;
      }
      printDFS(edges, n, i, visited); // recrusion
    }
  }
}
void DFS_discon(int**edges ,int n){
  bool *visited = new bool[n];
  for(int i = 0;i<n;i++){       // array to mark the visited elements
    visited[i] = false;
  }

  for(int i = 0;i<n;i++){
    if(!visited[i]){
      printDFS(edges,n,i,visited);
    }
  }
  delete[]visited;

}

void printBFS(int**edges,int n,int sv,bool*visited){
  queue<int> pendingVertices;

  pendingVertices.push(sv);
  visited[sv] = true;

  while(!pendingVertices.empty()){
    int currentVertex = pendingVertices.front();
    pendingVertices.pop();
    cout<<currentVertex<<" ";

    for(int i = 0;i<n;i++){
      if(currentVertex == i){
        continue;
      }
      if(edges[currentVertex][i] == 1 && !visited[i]){      //same as above commented code
        pendingVertices.push(i);
        visited[i] = true;
      }
    }
  }
}
void BFS_discon(int**edges,int n){
  bool *visited = new bool[n];
  for(int i = 0;i<n;i++){       // array to mark the visited elements
    visited[i] = false;
  }

  for(int i = 0;i<n;i++){
    if(!visited[i]){
      printBFS(edges,n,i,visited);
    }
  }
  delete[]visited;
}

int main(){
  //                    Creating a graph-->

  int n, e;  // n->no of vertices ,e->no of edges
  cout<<"enter no of vertices and no of edges ";
  cin>>n>>e;

  int* *edges = new int*[n];
  for(int i = 0;i<n;i++){
    edges[i] = new int[n];    //creating nXn 2D array dynamically
  }

  for(int i = 0;i<e;i++){
    int f, s;
    cin>>f>>s; //running loop e(edges) times and taking as input the vertices joined by each edge
    edges[f][s] = 1;
    edges[s][f] = 1;  //setting both (f,s) and (s,f) as '1'
  }
  // Graph is created!!

  //                    Depth First Search
  cout<<"DFS: ";
  DFS_discon(edges,n);
  cout<<endl;


  //                    Breadth First Search
  cout<<"BFS: ";
  BFS_discon(edges,n);

  // deleting allocated memory
  for(int i = 0;i<n;i++){
    delete [] edges[i];
  }
  delete[]edges;

//inputs and ouputs
// 7 5
// 0 2
// 0 3
// 2 3
// 1 4
// 5 6
// DFS: 0 2 3 1 4 5 6 
// BFS: 0 2 3 1 4 5 6


  return 0;
}
