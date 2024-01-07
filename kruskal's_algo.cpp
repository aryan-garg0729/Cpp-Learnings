#include <iostream>
using namespace std;
#include<algorithm>

//custom class for storing input 
class edge{
    public:
    int source; //source node
    int dest;   //destination node
    int weight; //weight of edge
    edge(){
        weight = 0;
    }
};

// used in sorting
bool compare(edge e1,edge e2){
    return e1.weight<e2.weight;
}

//finding parent of a node
int findparent(int i,int*parent){ // T = O(n)  n = no. of vertices
    while(i!=parent[i]){
        i = parent[i];
    }
    return i;
}

void kruskal(edge*input,int e,int n){
    //sorting input array
    sort(input,input+e,compare);  //T = O(eloge)
    
    //output array
    edge *output = new edge[n-1];
    
    //parent array 
    int parent[n];
    for(int i = 0;i<n;i++){
        parent[i] = i;      //initially parent of each node is the node itself
    }
    
    
    int count = 0;  //counts no. of edges in answer
    int i = 0;  //iterates through edges in input

    while(count!=n-1){   //   T = (E)(n[findparent]) =>O(E*n)=> O(n^3)
        edge e = input[i];
        int sourceParent = findparent(e.source,parent);
        int destParent = findparent(e.dest,parent);  //finding parents
        if(sourceParent!=destParent){ 
            output[count] = e;  //if parents are different edge is safe to add
            count++;
            parent[sourceParent] = parent[destParent]; //updating parent
        }
        i++;
        
    }
    
    //printing output
    for(int i = 0;i<n-1;i++){
        if(output[i].source<output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" ";
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" ";
        }
        cout<<output[i].weight<<endl;
    }
    
    delete []output;
}

int main() {
	int v,e;
    cin>>v>>e;
    edge *input = new edge[e]; //input array
    for(int i = 0;i<e;i++){
        cin>>input[i].source;
        cin>>input[i].dest;          //taking input
        cin>>input[i].weight;
    }

    kruskal(input,e,v);

    delete[]input;
}