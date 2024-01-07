template<typename V>
class Node{
	public:
	Node * next;
	V data;
	Node(V data){
		next = NULL;
		this->data = data;
	}
};

template <typename T>
class QueueUsingArray {

	//data members
	T *data;   //-->array for queue
	int nextIndex;
	int firstIndex;
	int size;	//no. of elements
	int capacity; //total capacity of array

	public :
	QueueUsingArray(int s) {//constructor
		data = new T[s];   //creating array dynamically
		nextIndex = 0;     //initialising variables
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	// insert element
	void enqueue(T element) {
		if(size == capacity) {
			cout << "Queue Full ! " << endl;
			return;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity ;  //to move queue circularly

		if(firstIndex == -1) {
			firstIndex = 0;//updating firstIndex only if the element entered is the first element
		}
		size++;
	}
	
	T front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	//delete element
	T dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		T ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;  //not done firstInd++ to move queue circularly
		size--;

	//reseting variables if queue becomes empty after dequeue.This step is not important and may be skipped 
		if(size == 0) {       
			firstIndex = -1;  
			nextIndex = 0;
		}

		return ans;
	}

};

template <typename T>
class DynamicQueue {

	//data members
	T *data;   //-->array for queue
	int nextIndex;
	int firstIndex;
	int size;
	int capacity; //total capacity of array

	public :
	DynamicQueue(int s) {//constructor
		data = new T[s];   //creating array dynamically
		nextIndex = 0;     //initialising variables
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	// insert element
	void enqueue(T element) {
		if(size == capacity) {
		// 	cout << "Queue Full ! " << endl;
		// 	return;

		int * newarr = new int[2*capacity];
		int j = 0;
		for(int i = firstIndex; i < capacity; j++,i++){
			newarr[j] = data[i];
		}
		for(int i = 0; i < firstIndex; j++,i++){
			newarr[j] = data[i];
		}
		delete [] data;
		data = newarr;
		nextIndex = capacity;
		firstIndex = 0;
		capacity*=2;

		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity ;  //to move queue circularly

		if(firstIndex == -1) {
			firstIndex = 0;//updating firstIndex only if the element entered is the first element
		}
		size++;
	}
	
	T front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	//delete element
	T dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		T ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;  //not done firstInd++ to move queue circularly
		size--;

	//reseting variables if queue becomes empty after dequeue.This step is not important and may be skipped 
		// if(size == 0) {       
		// 	firstIndex = -1;  
		// 	nextIndex = 0;
		// }

		return ans;
	}

};

template<typename T>
class QueueLL {
	// Define the data members
    Node<T> * head;
    Node<T> * tail;
    int size;
    
   public:
    QueueLL() {
		// Implement the Constructor
        head = NULL;
        tail = NULL;
        size = 0;
	}
	
	/*----------------- Public Functions of Queue -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
        return size==0;
	}

    void enqueue(int data) {                  //head-->| 1->2->3 |<--tail
		// Implement the enqueue() function   //head-->| 1->2->3->4 |<--tail
		Node<T> *nd = new Node<T>(data);
		
        if(head==NULL){
            head = nd;
            tail = head;
        }
        else{
            tail->next = nd;
            tail = nd;
        }
        size++;
	}

    T dequeue() {
        // Implement the dequeue() function
        if(head==NULL){
            return -1;					//head-->| 1->2->3->4 |<--tail
        }								//head-->| 2->3->4 |<--tail
        else{
            Node<T>*temp = head;
            T a = temp->data;
            head = head->next;
            delete temp;
            size--;
            return a;
        }
    }

    T front() {
        // Implement the front() function
        if(head==NULL){
            return -1;
        }
        return head->data;
    }
};


template<typename V>
class NodeD{    //doubly LL
	public:
	NodeD * next;
	NodeD * prev;
	V data;
	NodeD(V data){
		next = NULL;
		prev = NULL;
		this->data = data;
	}
};

template<typename T>
class DEQueueLL {
	// Define the data members
    NodeD<T> * head;
    NodeD<T> * tail;
    int size;
    
   public:
    DEQueueLL() {
		// Implement the Constructor
        head = NULL;
        tail = NULL;
        size = 0;
	}
	
	/*----------------- Public Functions of DEQueue -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
        return size==0;
	}

    void enqueueE(int data) {                  //head-->| 1<->2<->3 |<--tail
		// Implement the enqueueF() function   //head-->| 1<->2<->3<->4 |<--tail
		NodeD<T> * nd = new NodeD<T>(data);
		
        if(head==NULL){
            head = nd;
            tail = head;
        }
        else{
            tail->next = nd;
			nd->prev = tail;
            tail = nd;
        }
        size++;
	}

    void enqueueF(int data) {                  //head-->| 1<->2<->3 |<--tail
		// Implement the enqueueF() function   //head-->| 4<->1<->2<->3 |<--tail
		NodeD<T> * nd = new NodeD<T>(data);
		
        if(head==NULL){
            head = nd;
            tail = head;
        }
        else{
            head->prev = nd;
			nd->next = head;
            head = nd;
        }
        size++;
	}

    T dequeueF() {
        // Implement the dequeue() function
        if(head==NULL){
            return -1;					//head-->| 1->2->3->4 |<--tail
        }								//head-->| 2->3->4 |<--tail
        else{
            NodeD<T>*temp = head;
            T a = temp->data;
            head = head->next;
			if(head == NULL){
				tail = NULL;
			}
			else{
				head->prev = NULL;
			}
			delete temp;
        	size--;
        	return a;
        }
    }

    T dequeueE() {
        // Implement the dequeue() function
        if(head==NULL){
            return -1;					//head-->| 1->2->3->4 |<--tail
        }								//head-->| 2->3->4 |<--tail
        else{
            NodeD<T>*temp = tail;
            T a = temp->data;
            tail = tail->prev;
			if(tail==NULL){
				head = NULL;
			}
			else{
				tail->next = NULL;
			}
			delete temp;
        	size--;
            return a;
        }
    }

    T front() {
        // Implement the front() function
        if(head==NULL){
            return -1;
        }
        return head->data;
    }

    T rear() {
        // Implement the front() function
        if(head==NULL){
            return -1;
        }
        return tail->data;
    }
};
