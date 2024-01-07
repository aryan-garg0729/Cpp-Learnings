#include <iostream>
#include<climits>
using namespace std;
class Node{
    public:
    Node*next;
    int data;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class MyStack{
    int *data;
    int capacity;
    int nextIndex;

    public:
    MyStack(int totalSize){
        data = new int[totalSize];  //dynamically allocating array
        capacity = totalSize;
        nextIndex = 0;
    }

    // return number of elements present in the stack
    int size(){
        return nextIndex;
    }

    bool isEmpty(){

        /*if(nextIndex==0){
            return true;
        }
        else{
            return false;
        }*/

        return nextIndex==0;
    }

    // insert element
    void push(int a){
        if(nextIndex==capacity){
            cout<<"overflow"<<endl;
            return;
        }
        data[nextIndex] = a;
        nextIndex++;
    }

    // delete element
    int pop(){
        if(nextIndex==0){
            cout<<"stack is empty"<<endl;
            return INT32_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return INT16_MIN;
        }
        return data[nextIndex-1];
    }

};

class DynamicStack{
    int *data;
    int capacity;
    int nextIndex;

    public:
    DynamicStack(){
        data = new int[4];
        capacity = 4;
        nextIndex = 0;
    }

    // return number of elements present in the stack
    int size(){
        return nextIndex;
    }

    bool isEmpty(){

        /*if(nextIndex==0){
            return true;
        }
        else{
            return false;
        }*/

        return nextIndex==0;
    }

    // insert element
    void push(int a){
        if(nextIndex==capacity){
            int * newarr = new int[2*capacity];
            for(int i = 0;i<capacity;i++){
                newarr[i] = data[i];
            }
            capacity = 2*capacity;
            delete []data;
            data = newarr;
        }
        data[nextIndex] = a;
        nextIndex++;
    }

    // delete element
    int pop(){
        if(nextIndex==0){
            cout<<"stack is empty"<<endl;
            return INT32_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return INT16_MIN;
        }
        return data[nextIndex-1];
    }
};

class StackLL {
	// Define the data members
    Node * head;  //head of linked list
	int size;     //to keep track of size of stack
    public:
    StackLL() {
        // Implement the Constructor
        head = NULL;
        size = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return head==NULL;
    }

    void push(int element) {
        // Implement the push() function
        /*
        head-> 23->NULL (before push)
        head-> 34->23->NULL (after push)  34 is the top element
        after push head points to the new element which is then connected to old element 
        */
        Node *newnode = new Node(element);
        newnode->next = head;  /*connecting new node to old element(if it is the 1st element
                                then connecting it to NULL)*/

        head = newnode;        //head pointing to newnode
        size++;
    }

    int pop() {
        // Implement the pop() function
        if(head==NULL){
            return -1;
        }
        int a = head->data;   //storing data of node to be deleted
        Node * temp = head->next; /*storing address of next element of stack where the head will
                                  point after pop*/

        delete head;  //deleting the top node
        head = temp;  //head pointing to next element of stack
        size--;
        return a;    //returning the value of data of the deleted node
    }

    int top() {
        // Implement the top() function
        if(head!=NULL){
        	return head->data;
        }
        return -1;  //return -1 if stack is empty
    }
};

int main(){
    
    {MyStack s(4);

    cout<<s.isEmpty()<<endl;

    s.push(23);
    s.push(2);
    s.push(3);
    s.push(13);
    s.push(74);
    s.push(14);
    s.push(744);

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;

    cout<<s.top()<<endl;
    cout<<s.top()<<endl;

    cout<<endl;}

    {DynamicStack s1;

    cout<<s1.isEmpty()<<endl;

    s1.push(23);
    s1.push(2);
    s1.push(3);
    s1.push(13);
    s1.push(74);
    s1.push(14);
    s1.push(744);

    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;

    cout<<s1.size()<<endl;

    cout<<s1.top()<<endl;
    cout<<s1.top()<<endl;}


    return 0;
}