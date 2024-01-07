#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class MinPriorityQueue{
    vector<int> pq;

    public:

    bool isEmpty(){
        return pq.size()==0;
    }

    //returns size of priority queue i.e. no of element present
    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()){
            return INT16_MIN;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        int childIndex = pq.size()-1;
        int parentIndex = (childIndex-1)/2;

        while(childIndex > 0){ // run loop until the new element don't reach the top
            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];    //replace
                pq[parentIndex] = temp;
            }
            else{//--> pq[childIndex]>pq[parentIndex], element reached its correct pos so break
                break;
            }
            childIndex = parentIndex;
        }

    }

    int removeMin() {
        if (isEmpty()) {
            return INT16_MAX;
        }
        
        int ans = pq[0];  //storing deleted value to return it
        pq[0] = pq[pq.size()-1]; //replacing
        pq.pop_back();  //deleting
        
        int parentIndex = 0;
        int childIndex1 = 2*parentIndex+1;
        int childIndex2 = 2*parentIndex+2;
        int minind;
        
        while(childIndex1<pq.size()){
        	minind = parentIndex;  
            
        	if(pq[minind]>pq[childIndex1]){
            	minind = childIndex1;
        	}
        	if(childIndex2<pq.size() && pq[minind]>pq[childIndex2]){
            	minind = childIndex2;
        	}
            //now we have min of the three elements

            if(minind==parentIndex){     //if minind==parentIndex it means that element is at correct position so break
                break;
            }
            
            int temp = pq[minind];
            pq[minind] = pq[parentIndex];    //swaping parent with min
            pq[parentIndex] = temp;
            
            parentIndex = minind;
            childIndex1 = 2*parentIndex+1;
        	childIndex2 = 2*parentIndex+2;
            
        }   
        return ans;    
    }

};

class MaxPriorityQueue {
    // Declare the data members here
    vector<int> pq;
   public:

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] > pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty()){
            return INT16_MIN;
        }
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()){
            return INT16_MIN;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int parentIndex = 0;
        int childIndex1 = 2*parentIndex+1;
        int childIndex2 = 2*parentIndex+2;
        int maxind;
        
        while(childIndex1<pq.size()){
        	maxind = parentIndex;
            
        	if(pq[maxind]<pq[childIndex1]){
            	maxind = childIndex1;
        	}
            
        	if(childIndex2<pq.size() && pq[maxind]<pq[childIndex2]){
            	maxind = childIndex2;
        	}
            
            if(maxind==parentIndex){
                break;
            }
            
            int temp = pq[maxind];
            pq[maxind] = pq[parentIndex];
            pq[parentIndex] = temp;
            
            parentIndex = maxind;
            childIndex1 = 2*parentIndex+1;
        	childIndex2 = 2*parentIndex+2;
            
        }
        
        return ans;
        
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};

void heapSort(int arr[], int n){
    if (n < 2){
        return;
    }

    int i = 1;
    int childI = i;
    int parentI = (childI - 1) / 2;

    // max heap formation
    while (i != n){
        if (arr[childI] < arr[parentI]){
            int temp = arr[childI];
            arr[childI] = arr[parentI];
            arr[parentI] = temp;
            childI = parentI;
            parentI = (childI - 1) / 2;
        }
        else{
            i++;
            childI = i;
            parentI = (childI - 1) / 2;
        }
    }

    // deletion
    int minind;
    while (n - 1 != 0){
        int temp = arr[0];
    	arr[0] = arr[n - 1];  //swaping
    	arr[n - 1] = temp;

    	int parentIndex = 0;
    	int childIndex1 = 2 * parentIndex + 1;  //initialising variables
    	int childIndex2 = 2 * parentIndex + 2;
        n--;  //reducing size of arr
        while (childIndex1 < n){
            minind = parentIndex;

            if (arr[minind] > arr[childIndex1]){
                minind = childIndex1;
            }
            if (childIndex2 < n && arr[minind] > arr[childIndex2]){
                minind = childIndex2;
            }
            //now we have min 
            if (minind == parentIndex){
                break;             //element is at correct pos so break
            }

            int temp = arr[minind];
            arr[minind] = arr[parentIndex];  //swaping with min element
            arr[parentIndex] = temp;

            parentIndex = minind;
            childIndex1 = 2 * parentIndex + 1; //new child and parent
            childIndex2 = 2 * parentIndex + 2;
        }
    }
}

void kSortedArray(int input[], int n, int k) {
	priority_queue<int> pq;
	for(int i = 0; i < k; i++){
		pq.push(input[i]);          //push k elements to pq
	}

	int j = 0;
	for(int i = k; i < n; i++) {
		input[j] = pq.top();    //putting the max elements of pq into the array
		pq.pop();               //removing that element from pq
		pq.push(input[i]);      //pushing next element of array into pq
		j++;
	}

    //now all elements are sorted except the k elements that are still in pq so put all those in array  
	while(!pq.empty()) {
		input[j] = pq.top();
		pq.pop();
        j++;
	}

}

vector<int> kSmallest(int arr[], int n, int k) {
    priority_queue<int> pq;   //max priority queue
    vector<int> ans;
    
    for(int i = 0;i<k;i++){
        pq.push(arr[i]);    //let the first k elements be smallest and push them into pq
    }
    
    for(int i = k;i<n;i++){
        if(pq.top()>arr[i]){
            pq.pop();       //compare the top of pq(max elem) with the next element of array 
                        //and if the array elem is smaller so remove top and push that element
            pq.push(arr[i]);
        }
    }
    
    //now pq contains all k smallest elements so put them in a vector and return vector
    for(int i = 0;i<k;i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
}

vector<int> kLargest(int arr[], int n, int k){
    priority_queue<int,vector<int>,greater<int>> pq;  //min priority queue
    vector<int> ans;
    
    for(int i = 0;i<k;i++){
        pq.push(arr[i]);     //let the first k elements be largest and push them into pq
    }
    
    for(int i = k;i<n;i++){
        if(pq.top()<arr[i]){
            pq.pop();           //compare the top of pq(min elem) with the next element of array 
                        //and if the array elem is greater so remove top and push that element
            pq.push(arr[i]);
        }
    }

    //now pq contains all k largest elements so put them in a vector and return vector
    for(int i = 0;i<k;i++){
        ans.push_back(pq.top());  
        pq.pop();
    }
    
    return ans;

}

int kthLargest(int* arr, int n, int k) {
    priority_queue<int,vector<int>,greater<int>> pq;  //min priority queue
    
    for(int i = 0;i<k;i++){
        pq.push(arr[i]);     //let the first k elements be largest and push them into pq
    }
    
    for(int i = k;i<n;i++){
        if(pq.top()<arr[i]){
            pq.pop();           //compare the top of pq(min elem) with the next element of array 
                        //and if the array elem is greater so remove top and push that element
            pq.push(arr[i]);
        }
    }

    //now pq contains all k largest elements and the smallest of them is the kth largest element so return top of min priority queue
    return pq.top();
}

bool isMaxHeap(int arr[], int n){
    //METHOD 1:- USING QUEUE
    // if (n < 2){
    //     return true;
    // }

    // queue<int> pendingI;
    // int parent = 0;
    // pendingI.push(parent);

    // while (!pendingI.empty()){

    //     int front = pendingI.front();
    //     pendingI.pop();

    //     int ch1 = 2 * front + 1;
    //     int ch2 = 2 * front + 2;

    //     if (ch1 < n && arr[ch1] > arr[front]){
    //         return false;
    //     }
    //     else if (ch2 < n && arr[ch2] > arr[front]){
    //         return false;
    //     }
    //     else{
    //         if (ch1 < n){
    //             pendingI.push(ch1);
    //             if (ch2 < n){
    //                 pendingI.push(ch2);
    //             }
    //         }
    //     }
    // }
    // return true;

//  METHOD 2:-
    for (int i = 0; 2 * i + 1 < n; i++){

        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;

        if (arr[i] < arr[leftChildIndex]){
            return false;
        }
        if (rightChildIndex < n && arr[i] < arr[rightChildIndex]){
            return false;
        }
        
    }
    return true;
}

//running median IMP
void findMedian(int *arr, int n){
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;//creating min pq
    
    for(int i = 0;i<n;i++){
        if(max.empty() && min.empty()){
        	max.push(arr[0]);
            cout<<max.top()<<" ";
            continue;
    	}
        if(arr[i]<=max.top()){
            max.push(arr[i]);
            if((max.size()+min.size())%2==0 && max.size()>min.size()){
                min.push(max.top());
                max.pop();
            }
            
        }
        else if(arr[i]>max.top()){
            min.push(arr[i]);
            if((max.size()+min.size())%2==0 && max.size()<min.size()){
                max.push(min.top());
                min.pop();
            }
            
        }
        if((max.size()+min.size())%2==0){
            cout<<(max.top()+min.top())/2<<" ";
        }
        else{
            max.size()>min.size()?cout<<max.top()<<" ":cout<<min.top()<<" ";
        }
    }
}

vector<int> mergeKSortedArraysM1(vector<vector<int>*> input) {  //unoptmised
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0;i<input.size();i++){
        for(int j = 0;j<input[i]->size();j++){  //put everything in min pq
            pq.push(input[i]->at(j));
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());  //pop everything from pq
        pq.pop();
    }
    return ans;
}

class triplet{
    public:
    int data;
    int ind; //index of element
    int arr; //array number to which element belongs
    triplet(int data,int ind,int arr){
        this->data = data;
        this->ind = ind;
        this->arr = arr;
    }
};
class comp{  //comparator class for priority queue
    public:
    bool operator()(const triplet& a,const triplet& b){ //overloading operator()
        if(a.data>b.data){
            return true;
        }
        else{
            return false;
        }
    }
};
vector<int> mergeKSortedArraysM2(vector<vector<int>*> input) { //optimised
    priority_queue<triplet,vector<triplet>,comp>pq;

    for(int i =0;i<input.size();i++){
        triplet t(input[i]->at(0),0,i); //pushing 1st element of every array
        pq.push(t);
    }

    vector<int> ans ;

    while(pq.size()!=0){
        triplet t = pq.top();   //getting top elem of pq
        pq.pop();               //removing from pq
        ans.push_back(t.data);  //storing data to ans vector
        t.ind++;                //incrementing index for that element
        if(t.ind<input[t.arr]->size()){
            t.data = input[t.arr]->at(t.ind); //updating data and pushing into pq
            pq.push(t);
        }
        
    }
    return ans;
}

int buyTicket(int *arr, int n, int k) {
    priority_queue<int>pq;
    queue<int>q;
    for(int i = 0;i<n;i++){
        pq.push(arr[i]);
        q.push(i);
    }
    int t = 0;
    while(true){
        if(arr[q.front()]==pq.top()){
            t++;      
            pq.pop();
            if(q.front()==k){
                return t;
            }
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
}


