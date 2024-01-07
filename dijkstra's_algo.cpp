#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(int* distance, bool* visited, int n){  //TC = O(n)

	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int** edges, int n){
	int* distance = new int[n]; //stores distances of each vertex from source vertex
	bool* visited = new bool[n];//checks if a node is visited or not

	for(int i = 0; i < n; i++){
		distance[i] = INT_MAX;  //initially all distances are infinite
		visited[i] = false;     //initially all nodes are unvisited
	}

	//taking '0' as source node so its distance from itself is 0
	distance[0] = 0;  

	for(int i = 0; i < n - 1; i++){ //runs n-1 times, total TC = O((n-1)*n) => O(n^2)
		int minVertex = findMinVertex(distance, visited, n); //TC = O(n)
		visited[minVertex] = true; //find minvertex and mark visited

		//exploring unvisited neighbours
		for(int j = 0; j < n; j++){	  //TC = O(n)
			if(edges[minVertex][j] != 0 && !visited[j]){
				int dist = distance[minVertex] + edges[minVertex][j];
				if(dist < distance[j]){
					distance[j] = dist;
				}
			}
		}
	}
	
	//printing
	for(int i = 0; i < n; i++){
		cout << i << " " << distance[i] << endl;
	}
	delete [] visited;
	delete [] distance;
	
}

int main() {
	int n,e;
	cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	//adjacency matrix with weights
	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout << endl;
	dijkstra(edges, n);

	//deletion
	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}
