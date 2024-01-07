#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(int* weights, bool* visited, int n){  //it visits all vertex so TC = O(n)
	int minVertex = -1; //initially none is min vertex 
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == - 1 || weights[i] < weights[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void prims(int** edges, int n){

	int* parent = new int[n];  //stores the parent of vertex
	int* weights = new int[n]; //stores weights of vertex
	bool* visited = new bool[n];//checks if the vertex is visited or not

	for(int i = 0; i < n; i++){	//initialising array
		visited[i] = false;    //initially all are unvisited
		weights[i] = INT_MAX;  //initially all have weight as infinity  
	}
	//taking 0 as starting point
	parent[0] = -1;  //as no parent of starting point
	weights[0] = 0;  //initial weight = 0

	for(int i = 0; i < n - 1; i++){ //runs n-1 times,so total TC = O((n-1)*n) = O(n^2)
		// Find Min Vertex and mark as visited
		int minVertex = findMinVertex(weights, visited, n);  //TC = O(n)
		visited[minVertex] = true;
		// Explore unvisited neighbours
		for(int j = 0; j < n; j++){   //TC = O(n)
			if(edges[minVertex][j] != 0 && !visited[j]){
				if(edges[minVertex][j] < weights[j]){  //if (edge weight)<(node weight)
					weights[j] = edges[minVertex][j];  //(node weight) = (edge weight)
					parent[j] = minVertex;             //set parent of that vertex
				}
			}
		}
	}

    //printing
	for(int i = 1; i < n; i++){
		if(parent[i] < i){
			cout << parent[i] << " "<< i << " " << weights[i] << endl;
            }
            else{
			cout << i << " " << parent[i] << " " << weights[i] << endl;
		}
	}
}

int main() {
	int n,e;
	cin >> n >> e;
	int* *edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	//Adjacency matrix with weights
	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}

	prims(edges, n);

	//deletion
	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}