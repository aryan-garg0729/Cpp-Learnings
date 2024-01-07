#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
void getPathBFS(int**edges,int n,int v1,int v2,bool*visited){
    queue<int> pendingVertices;
    unordered_map<int, int> m; //m[i] tells who entered i into queue (i is entered into Queue by m[i])

    pendingVertices.push(v1);
    visited[v1] = true;
    bool found = false;

    while(!pendingVertices.empty()){
        int currVertex = pendingVertices.front();
        pendingVertices.pop();
        
        for(int i  = 0;i<n;i++){
            if(edges[currVertex][i]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;

                m[i] = currVertex;// doing entry into map who entered i into queue
                if(i==v2){  //if i==v2 we got path
                    found = true;
                    break;
                }
            }
        }
            if(found){
                break;
            }
    }

    if(found){  //if we got path then printing path
        cout<<v2<<" ";
        int a = v2;
        while(true){
            cout<<m[a]<<" ";  //using map to trace the path
            a = m[a];
            if(a==v1){
                break;
            }
        }
    }

    return;
}

vector<int> getPathDFS(int* *edges,int n,int v1,int v2,bool *visited){
    vector<int> p;
    if(v1==v2){
        p.push_back(v1);
        return p;
    }

    visited[v1] = true;
    for(int i = 0;i<n;i++){
        if(!visited[i] && edges[v1][i]==1){
            vector<int> p1 = getPathDFS(edges,n,i,v2,visited);
            if(p1[0]==v2){
            	p = p1;
                break;
            }
            
        }
    }
    
    p.push_back(v1);
    return p;
}

/*Q: check if the graph is connected or not
 Ans: perform bfs or dfs and check visited array.If any vertex is unvisited then disconnected else connected
*/

/*all connected components*/
vector<int> BFS(int **edges, int n, int sv, bool *visited) {
  queue<int> pendingVertices;
  vector<int> smallans;

  pendingVertices.push(sv);
  smallans.push_back(sv);
  visited[sv] = true;

  while (!pendingVertices.empty()) {
    int currentVertex = pendingVertices.front();
    pendingVertices.pop();

    for (int i = 0; i < n; i++) {
      if (edges[currentVertex][i] == 1 &&
          !visited[i]) { // same as above commented code
        pendingVertices.push(i);
        smallans.push_back(i);
        visited[i] = true;
      }
    }
  }
  return smallans;
}
vector<vector<int>> BFS_discon(int **edges, int n) {
  vector<vector<int>> ans;
   bool *visited = new bool[n];
  for (int i = 0; i < n; i++) { // array to mark the visited elements
    visited[i] = false;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
     vector<int> smallans = BFS(edges, n, i, visited);
     sort(smallans.begin(),smallans.end());
     ans.push_back(smallans);
    }
  }
  delete[] visited;
  return ans;
}


/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
4 4
CANI
OOJN
DDIG
JNIN -->true
*/
int validPoint(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
bool dfs(vector<vector<char>> &board, vector<vector<bool>> &used, string &word, int x, int y,int wordIndex, int n, int m){
    if (wordIndex == 11){
        return true;
    }
    used[x][y] = true;
    bool found = false;
    int dXdY[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < 8; ++i){
        int newX = x + dXdY[i][0];
        int newY = y + dXdY[i][1];
        if (validPoint(newX, newY, n, m) && board[newX][newY] == word[wordIndex] && !used[newX][newY]){
            found = found | dfs(board, used, word, newX, newY, wordIndex + 1, n, m);
        }
    }
    used[x][y] = false;
    return found;
}
bool hasPath(vector<vector<char>> &board, int n, int m){
    bool foundPath = false;
    string word = "CODINGNINJA";
    vector<vector<bool>> used(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == word[0]){
                foundPath = dfs(board, used, word, i, j, 1, n, m);
                if (foundPath)
                    break;
            }
        }
        if (foundPath)
            break;
    }
    return foundPath;
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}

/*It's Gary's birthday today and he has ordered his favourite square cake consisting of 
'0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is 
defined as a part which consist of only '1's, and all '1's share an edge with each other on 
the cake. Given the size of cake N and the cake, can you find the count of '1's in the 
biggest piece of '1's for Gary ?*/
bool isvalid(int x,int y,int n){
    if(x<n && x>=0 && y<n && y>=0){
        return true;
    }
    return false;
}
int dfs(vector<vector<int>> &cake, int n,vector<vector<bool>> &used,int x,int y){
    used[x][y]=true;
    int count = 0;
    int arr[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
    for(int i = 0;i<4;i++){
        int newx = x;
        int newy = y;
        newx+=arr[i][0];
        newy+=arr[i][1];
        if(isvalid(newx,newy,n) && !used[newx][newy] && cake[newx][newy]==1){
            count+=dfs(cake,n,used,newx,newy);
        }
    }
    return count+1;
}
int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
  vector<vector<bool>> used(n, vector<bool>(n, false));
  int ans = 0;
  int count = 0;
  for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++){
          if(cake[i][j]==1){
              count = dfs(cake,n,used,i,j);
              ans = max(count,ans);
          }
      }
  }
  return ans;
}
int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}

int threecycle(int**edges,int n){ //number of cycles which have 3 vertices
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                if(edges[i][j]==1 && edges[j][k]==1 && edges[i][k]==1){
                    count++;
                }
            }
        }
    }
    return count/6;
}

void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int x,
         int y, int fromX, int fromY, char needColor, bool &foundCycle, int n,
         int m) {
  if (x < 0 || x >= n || y < 0 || y >= m) {
    return;
  }
  if (board[x][y] != needColor) {
    return;
  }
  if (visited[x][y]) {
    foundCycle = true;
    return;
  }
  visited[x][y] = true;
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  for (int i = 0; i < 4; ++i) {
    int nextX = x + dx[i];
    int nextY = y + dy[i];
    if (nextX == fromX && nextY == fromY) {
      continue;
    }
    dfs(board, visited, nextX, nextY, x, y, needColor, foundCycle, n, m);
  }
}
bool hasCycle(vector<vector<char>> &board, int n, int m) {
  bool foundCycle = false;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        dfs(board, visited, i, j, -1, -1, board[i][j], foundCycle, n, m);
      }
    }
  }
  return foundCycle;
}

int main() {
//----------------- Creating Graph--------------------
    int n,e;
    cin>>n>>e;

    int* *edges = new int*[n];
    for(int i = 0;i<n;i++){
        edges[i] = new int[n];
        for(int j = 0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
      int f, s;
      cin >> f >> s; // running loop e(edges) times and taking as input the
                     // vertices joined by each edge
      edges[f][s] = 1;
      edges[s][f] = 1; // setting both (f,s) and (s,f) as '1'
    }

    bool *visited = new bool[n];
    for(int i =0 ;i<n;i++){
        visited[i] = false;
    }

//-------------------Function Calls-------------------------------------
    int v1,v2;
    cin>>v1>>v2;

    getPathBFS(edges, n,  v1,  v2,visited);

    vector<int> p = getPathDFS(edges,n,v1,v2,visited);
    if(p[0]==v2){
        for(int i = 0;i<p.size();i++){
        	cout<<p[i]<<" ";
    	}
    }

    cout<<threecycle(edges,n);

//--------------Deleting Dynamically Allocated Space--------------------
    delete[]visited;
    for(int i = 0;i<n;i++){
        delete[]edges[i];
    }
    delete[]edges;

    return 0;
}