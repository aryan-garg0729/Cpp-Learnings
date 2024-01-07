#include<iostream>
using namespace std;
class Node
{
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
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
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

Node *evenAfterOdd(Node *head)
{
	Node *oddh = NULL,*oddt = NULL,*evenh = NULL,*event =NULL;

    while(head!=NULL){
        if(head->data%2==0){
            if(evenh==NULL){
                evenh = head;
                event = head;
            }
            else{
                event->next = head;
                event = head;
            }
            
        }
        else{
            if(oddh==NULL){
                oddh = head;
                oddt = head;
            }
            else{
                oddt->next = head;
                oddt = head;
            }
            
        }
        head = head->next;
    }

    if(oddh==NULL){
        return evenh;
    }
    if(evenh==NULL){
        return oddh;
    }

    oddt->next = NULL;
    event->next = NULL;
    oddt->next = evenh;
    return oddh;    
}

Node *swapNodes(Node *head, int i, int j)
{
    Node* temp = head;
    Node* temp1 = head;
	while(i){
        temp = temp->next;
        i--;
    }
    while(j){
        temp1 = temp1->next;
        j--;
    }
    int t = temp->data;
    temp->data = temp1->data;
    temp1->data = t;
    return head;
}

Node* kReverse(Node*head,int n)
{
    if(n==0){
        return head;
    }
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* current = head;
    Node* temp = head;
    Node* pre = NULL;
    int i = 0;
    while(current!=NULL && i<n){
        temp = temp -> next;
        current->next = pre;
        pre = current;
        current = temp;
        i++;
    }
    if(temp != NULL){
        head->next = kReverse(temp,n);
    }
    return pre;
}

void del(Node*head){
    if(head==NULL){
        return;
    }
    del(head->next);
    delete head;
}
Node *skipMdeleteN(Node *head, int M, int N)
{
    Node*t1 = head;
    Node*t2 = head;
    Node*rem = NULL;
    int n = 1;
    int m = 1;
    if(N==0){
    	return head;        
    }
    if(M==0){
        del(head);
        return NULL;
    }
	while(1){
        while(m<M){
            if(t1 == NULL){
                return head;
            }
            t1 = t1->next;
            m++;
        }
        if(t1==NULL){
            return head;
        }
        t2 = t1->next;
        while(n<N){
            if(t2 == NULL){
                break;
            }
            t2 = t2->next;
            n++;
        }
        rem = t2;
        if(t2!=NULL){
            t2 = t2->next;
            rem->next = NULL;
        }
        
        
        rem = t1->next;
        del(rem);
        t1->next = t2;
        if(t1==NULL||t2==NULL){
            return head;
        }
        t1 = t2;
        n=1;
        m=1;
        
    }
}



int main(){
    Node * head = takeinput();
    head = evenAfterOdd(head);
    print(head);
    return 0;
}