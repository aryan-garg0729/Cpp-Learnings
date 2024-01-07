#include<iostream>
using namespace std;
#include<queue>
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};
template <typename T>
class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	if(root == NULL){
        return false;   //base case
    }
    
    else if(root->data == k){
        return true;      //base case
    }  

    else if(root->data>k){
        return searchInBST(root->left,k);
    }  

    else if(root->data<k){
        return searchInBST(root->right,k);
    }
    
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if(root == NULL){
        return;        //base case
    }
    
    if(root->data>k2){
        elementsInRangeK1K2(root->left,k1,k2);
        return;
    }
    else if(root->data<k1){
        elementsInRangeK1K2(root->right,k1,k2);
        return;
    }
    else{
        elementsInRangeK1K2(root->left,k1,k2);
        cout<<root->data<<" ";
        elementsInRangeK1K2(root->right,k1,k2);
        return;
    }
    
}

int minimum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT16_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT16_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST1(BinaryTreeNode<int>* root){
    if(root == NULL){
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data<rightMin) && (root->data>leftMax) && (isBST1(root->left)) && (isBST1(root->right));

    return output;
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    if(data<root->data){
        vector<int>*leftOutput = getPath(root->left,data);
    	if(leftOutput != NULL){
        	leftOutput->push_back(root->data);
        	return leftOutput;
    	}
    }
    if(data>root->data){
        vector<int>*rightOutput = getPath(root->right,data);
    	if(rightOutput != NULL){
        	rightOutput->push_back(root->data);
        	return rightOutput;
    	}
    }
    
    else{
        return NULL;
    }
}

//****VVVI****
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> level;
    if(root == NULL){
        return level;     //edge case
    }  
    
    queue<BinaryTreeNode<int>*> pendingNodes;  //contains pending nodes
    
    pendingNodes.push(root);
    pendingNodes.push(NULL);  
    /*
	we are using null as a breaking point i.e. where we have create new LL.
	we have to add null after every level of the tree so that we create new LL
	after every level
	*/
    Node<int>* head = NULL;
    Node<int>* tail = NULL;  //head and tail of our LL
    
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        while(front != NULL){
            Node<int>*node = new Node<int>(front->data);  //creating node

            if(head==NULL){
                head = node;
                tail = head;
            }                         //making connections
            else{
                tail->next = node;
                tail = tail->next;
            }


            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }


            front = pendingNodes.front();
        	pendingNodes.pop();
            
            if(front==NULL){
                pendingNodes.push(NULL);   //adding new breaking point for next LL
            }
            
        }

        level.push_back(head);  //storing head of our LL in the vector level

        head = NULL;  //reinitialising head and tail to NULL
        tail = NULL;
    }
    return level;
    
}

BinaryTreeNode<int>*insertDuplicateNode2(BinaryTreeNode<int>*root){
    if(root == NULL){
        return NULL;   //base case
    }

    BinaryTreeNode<int>*temp = insertDuplicateNode2(root->left);   //rec call
    root->right = insertDuplicateNode2(root->right);

    BinaryTreeNode<int>*node = new BinaryTreeNode<int>(root->data);
    root->left = node;                                              //small calc
    node->left = temp;

    return root;
}


class BST{
    BinaryTreeNode<int> *root;

public:
    BST(){
        root = NULL;
    }

    ~BST(){
        delete root;
    }

private:
    BinaryTreeNode<int> *remove(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL){
            return NULL;
        }
        if (data > node->data){
            node->right = remove(node->right, data);
            return node;
        }
        else if (data < node->data){
            node->left = remove(node->left, data);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if (node->left == NULL){
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL){
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = remove(node->right, rightMin);
                return node;
            }
        }
    }

    void print(BinaryTreeNode<int> *root){
        if (root == NULL){
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL){
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != NULL){
            cout << "R:" << root->right->data;
        }
        cout << endl;
        print(root->left);
        print(root->right);
    }

    bool search(BinaryTreeNode<int> *node, int data){
        if (node == NULL){
            return false;
        }
        if (node->data == data){
            return true;
        }
        else if (data < node->data){
            return search(node->left, data);
        }
        return search(node->right, data);
    }

    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *node, int data){
        if (node == NULL){
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data <= node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;
    }

public:
    void remove(int data)
    {
        root = remove(root, data);
    }
    void print()
    {
        print(root);
    }
    void insert(int data){
        this->root = insert(this->root, data);
    }
    bool search(int data){
        return search(root, data);
    }

};


