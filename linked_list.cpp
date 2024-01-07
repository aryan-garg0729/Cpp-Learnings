#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node *next;         //to store address of next element of list
	Node(int data)     //constructor to initialise data
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)    //take input till input!= -1
    {
		Node *newNode = new Node(data);
		if (head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;   //connecting 2 nodes
			tail = newNode;        //setting tail pointer to last element
		}
		cin >> data;
	}
	return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void printIthNode(Node *head, int i)
{
    Node *temp = head;
    for(;i>=0&&temp!=NULL;i--){
        if(i==0){
            cout<<temp->data;
            return;
        }
        temp = temp->next;
        // temp = (*temp).next;
    }
    return;
}

Node *deleteNode(Node *head, int i)
{
    if(head == NULL){
        return head;
    }
    Node*temp = head;
    if(i==0){
        Node*a = head;
        head = head->next;
        delete a;
        return head;
    }
    for(;i>1;i--){
        temp = temp->next;
        if(temp->next==NULL){
            return head;
        }
    }
    Node*a = temp->next;
    temp->next = a->next;
    delete a;
    return head;
}

int length_loop(Node *head)
{
    Node *temp = head;
    int l = 0;
    if(temp!=NULL){
    	while(temp->next!=NULL){
    	    l++;
    	    temp = temp->next;
    	}
    	return ++l;
    }
    return 0;
}

int length(Node *head) {
    if(head==NULL){
        return 0;
    }
    int l = length(head->next);
    return l+1;
     
}

int findNode(Node *head, int n){
    Node *temp = head;
    int ind = 0;
    while(temp!=NULL){
        if(temp->data == n){
        	return ind;
    	}
    	else{
        	temp = temp->next;
        	ind++;
    	}
    }
    return -1;
}

int findNodeRec(Node *head, int n)
{
	if(head==NULL){
        return -1;
    }                               //base case
    else if(head->data==n){
        return 0;
    }

    int i = findNodeRec(head->next,n); //rec call

    if(i==-1){
        return -1;            //small calc
    }

    return i+1;
}

Node *appendLastNToFirst(Node *head, int n)
{
    if(head==NULL){
        return head;
    }
    if(n==0){
        return head;
    }
    
    Node *temp = head;
    Node *newhead;
    int len = length(temp);
    int m = len-n;
    while(--m){
        temp = temp->next;
    }
    Node *a = temp;
    newhead = temp->next;
    a->next = NULL; 
    temp = newhead;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head;
    return newhead;
	/*
input:
1
10 6 77 90 61 67 100 -1
4
output:
90 61 67 100 10 6 77 
	*/
}

Node* insertNode(Node *head, int i, int data) {
	/*insert node at index 'i' recursively*/
	if(head==NULL){  //base condition
        return head;
    }
    if(i==0){         //small calc(creating new node and making link)
        Node *n = new Node(data);
        n->next = head;
        head = n;
        return head;
    }
    Node* temp = insertNode(head->next,i-1,data); //calling recursion
    head->next = temp;
    return head;
}

Node *deleteNodeRec(Node *head, int i) {
	if(head == NULL){  //base case
        return head;
    }
    
    Node *temp = head;    //small calc
    if(i==0){
        head = head->next;
        delete temp;
        return head;
    }
    
    temp = deleteNodeRec(head->next,i-1);  //rec call
    head->next = temp;
    return head;
    
}

Node* removeNthFromEnd(Node* head, int n) {
    /*take 3 pointers: 
    pre -> points to the node prevoius to node to be deleted
    slow ->at last it will point to the node to be deleted
    fast -> at last it will point to the last node

    all move by one step at a time but fast and slow have difference of n-2 nodes always 
    so when fast points to last node slow points to node to be deleted(nth node from last)
    */
        Node*pre = NULL;//always precedes the slow pointer
        Node*slow = head;
        Node*fast = head;
        for(int i = 1;i<n;i++){
            fast = fast->next;    //creating difference of n-2 nodes b/w fast and slow
        }
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
            if(pre!=NULL){
                pre = pre->next;
            }
            else{
                pre = head;
            }
        }
        if(slow == head){
            return head->next;
        }
        Node*n1 = slow->next;
        pre->next = n1;
        return head;
    }

void printReverse_rec(Node *head)
{
    if(head==NULL){    //base case
        return;
    }
    printReverse_rec(head->next);  //rec call
    cout<<head->data<<" ";  //small calc
    return;
    
}

bool isPalindrome(Node *head)
{
    bool odd = true;  // true if length is odd
    Node *temp = head;
    int l = length(head);  //checking length
    if(l%2==0){
        odd = false;
    }
    if(l<2){
        return true;  //if the length of the word is less than 2 then it is a palindrome
    }

    //splitting the list into 2 parts
    /*  let list is 2 3 5 3 2
        so l1 = 2 3
        l2 = 5 3 2
    */
    Node *head2 = NULL;
    l/=2;
    while(--l){
        temp = temp->next;
    }
    head2 = temp->next;
    temp->next = NULL;
    
    
    
    //reversing one of the list
    /* l1 = 3 2 (reversed)
       l2 = 5 3 2 
    */
    Node*h = NULL;
    while(head != NULL){
        Node* n = new Node(head->data);
        Node *p = head;
        head = head->next;
        delete p;
        if(h==NULL){
            h = n;
        }
        else{
            n->next = h;
            h = n;
        }
    }
    
    // comparing l1 and l2 if original list had even no of elements
    if(!odd){
    while(h!=NULL&&head2!=NULL){
        if(h->data!=head2->data){
            return false;
        }
        h = h->next;
        head2 = head2->next;
    }
    return true;
    }

      // comparing l1 and l2 if original list had odd no of elements
    else{
        head2 = head2->next;
        while(h!=NULL&&head2!=NULL){
        if(h->data!=head2->data){
            return false;
        }
        h= h->next;
        head2 = head2->next;
    }
    return true;
        
    }
}
// M2 recursive
pair<Node*,bool> helper(Node*s,Node*e){
  if(e==NULL)return {s,true};
  auto b = helper(s,e->next);
  if(!b.second)return {s,false};
  if(b.first->value != e->value)return {s,false};
  return {b.first->next,true};
}
bool Palindrome(Node* head) {
  return helper(head,head).second;
}


Node *removeDuplicates(Node *head)
{
    if(head==NULL){
        return head;
    }

    Node * t1 = head;
    Node * t2 = head;
    t2 = t2->next;

    while(t2!=NULL){
        if(t2->data==t1->data && t2->next==NULL){
            t1->next = NULL;
            t2 = t2->next;
        }
        else if(t2->data==t1->data){
            t2 = t2->next;
        }
        else{
            t1->next = t2;
            t1 =t2;
            t2 = t2->next;
        }
    }
    return head;
}

Node *midPoint(Node *head)
{
    if(head==NULL){
        return head;
    }
    
    Node * slow = head;
    Node * fast = slow->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node * h = NULL;
    Node * t = NULL;

    if(head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }
    
    if(head1->data>=head2->data){
        h = head2;
        t = h;
        head2 = head2->next;
    }
    else{
        h = head1;
        t = h;
        head1 = head1->next;
    }


    while(head1!=NULL && head2!=NULL){
        if(head2->data<=head1->data){
            t->next = head2;
            t = head2;
            head2 = head2->next;
        }
        else{
            t->next = head1;
            t = head1;
            head1 = head1->next;
        }
    }

    if(head1==NULL){
        t->next = head2;
    }
    else if(head2==NULL){
        t->next = head1;
    }
    
    return h;  
}

Node *mergeSort(Node *head)
{
    //base condition
	if(head ==NULL || head->next == NULL){
        return head;
    }

    // splitting linked list into two parts
    Node * head2 = NULL;
    int l = length(head);
    l = l/2;
    Node * temp = head;
    while(--l){
        temp = temp->next;
    }
    head2 = temp->next;
    temp->next = NULL;

    //recursion call
    head = mergeSort(head);
    head2 = mergeSort(head2);
    
    //merging the two sorted lists and returning result
    Node * result = NULL;
    result = mergeTwoSortedLinkedLists(head,head2);
    return result;
    
}




//Niave approach
Node * reverse_rec(Node * head){   // time complexity is O(n^2)

    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node * smallans = reverse_rec(head->next);
    Node * temp = smallans;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallans;
}

//best approach
Node * reverse_rec_best(Node * head){   // time complexity is O(n)

    if(head==NULL || head->next==NULL){  //base case
        return head;
    }
    
    Node * smallans = reverse_rec_best(head->next);  //rec call
    Node * tail = head->next; //eg: 1->2->3->NULL => after rec call => 1->2 | 3->2->NULL      NOTE that the node 1 still points to 2 so next of node 1 = &2 which is the tail

    tail->next = head;
    head->next = NULL;

    return smallans;
}


//good approach, but we have done this approach to learn how to return multiple objects(i.e.   we can use classes)
class Pair{    //classes can be used to return multiple objects
    public:
    Node * head;
    Node * tail;
};
Pair reverse_rec_better(Node * head){   // time complexity is O(n)

    if(head==NULL || head->next==NULL){
        Pair p;
        p.head = head;
        p.tail = head;
        return p;
    }
    
    Pair smallans = reverse_rec_better(head->next);
    Node * t = smallans.tail;
    Node * h = smallans.head;
    t->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;
}
Node * rll(Node*head){
    Pair ans;
    ans = reverse_rec_better(head);
    return ans.head;
}


// reversing iteratively
Node *reverseLLIterative(Node *head) {
    if(head==NULL||head->next == NULL){
        return head;
    }

    Node * prev = NULL, *curr = head, *next = head->next;

    while(1){
        if(curr==NULL){
            break;
        }

        //making reverse connections
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next!=NULL){
            next = next->next;
        }    
    } 

    return prev; 
}


Node *bubbleSort_iter(Node *head)
{
    if(head==NULL){
        return head;
    }

    Node * t = NULL;   //acts as tail pointer
	Node * temp = head;
    while(t!=head){
        while(temp->next!=t && temp!=NULL && temp->next!=NULL){
            if(temp->data>temp->next->data){
                int t1 = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t1;
            }
            
            temp = temp->next;
        }
        t = temp;
        temp = head;
        
    }
    return head;
}


int main(){
    // int t;
	// cin >> t;
    Node n;
    cout<<n.data;
	// while (t--)
	// {
	// 	Node *head1 = takeinput();
	// 	Node *head2 = takeinput();
	// 	Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
	// 	print(head3);

	// }
    // Node *head1 = takeinput();
    // print(head1);
    // insertNode(head1,2,34);
    // print(head1);
    // head1 = reverse_rec_best(head1);
    // print(head1);
    return 0;
}