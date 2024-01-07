#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include"BT.h"
template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    
    if(root==NULL){
        return;
    }
    
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    
}

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;    // if array is empty return NULL
	}

	int rootData = pre[preS];  //as preS is the index which contains the root
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {        //searching for root in inOrder array
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;
	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}
BinaryTreeNode<int>* buildTree(int* in, int* pre, int size) {
	return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

int getSum(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    
    return root->data + getSum(root->left) + getSum(root->right);
    
}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	//pair is inbuilt class with 2 attributes first and second 
	//min and max are also inbuilt and takes 2 arguments

	if(root == NULL){
        pair<int,int> ans;
        ans.first = INT16_MAX;
        ans.second = INT16_MIN;
        return ans;
    }
    
    pair<int, int> lans;
    lans = getMinAndMax(root->left);   //brings ans of left subtree
    pair<int, int> rans;
    rans = getMinAndMax(root->right);  //brings ans of right subtree
    
    pair<int,int> ans;
    
    int minL = lans.first;
    int minR = rans.first;
    ans.first = min(min(minL,minR),root->data);  //overall min
    
    int maxL = lans.second;
    int maxR = rans.second;
    ans.second = max(max(maxL,maxR),root->data);  //overall max
    
    return ans;
    
}

bool isBalanced(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return true;     //edge case;
    }
    if(root->left==NULL&&root->right==NULL){
        return true;                            //base case
    }
    
    int lh = height(root->left);
    int rh = height(root->right);

    int diff = lh-rh;

    if(diff==0||diff==1||diff==-1){
        bool b1 = isBalanced(root->left);
        bool b2 = isBalanced(root->right);
        return b1 && b2;           //returns true if both subtrees are balanced
    }

    return false;
    
}

//***** VVVI*****
void printLevelWise(BinaryTreeNode<int> *root) {
    
    if(root == NULL){
        return;      //edge case
    }
    
    queue<BinaryTreeNode<int> *> pendingNodes; //contains nodes to be printed
    
    pendingNodes.push(root);
    pendingNodes.push(NULL); // one level completed so add NULL
	/*
	we are using null as a breaking point i.e. where we have to print new line
	if we encounter null and the queue is not empty then we will print endl
	we have to add null after every level of the tree so that we move to next line 
	after every level
	*/
    
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        
        while(front!=NULL){
            
            cout<<front->data<<" "; //printing element of that level
            
            if(front->left!=NULL){  //add front->left to queue only if it is not null as we have chosen null as our breaking point
                pendingNodes.push(front->left);
            }
            
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
            
            front = pendingNodes.front();
            pendingNodes.pop();
            
            if(front==NULL){  //if we get null it means printing of a level and addition of next level to queue is completed so add null to queue
                pendingNodes.push(NULL);
            }
        }
        if(!pendingNodes.empty()){
            cout<<endl;  //since we are out of the loop it means front is NULL ,now if queue is not empty then print new line else exit
        }
       
    }
    return;
    
}
//***** VVVI*****
void zigZagOrder(BinaryTreeNode<int> *root) {
    stack<BinaryTreeNode<int> *> s1;  // elements from L(top)->R
    stack<BinaryTreeNode<int> *> s2;  // elements from R(top)->L
    
    s1.push(root);

    while(!s1.empty() || !s2.empty()){
        BinaryTreeNode<int> * top;

        while(!s1.empty()){
            top = s1.top();
            s1.pop();
            
            if(top->left!=NULL){
                s2.push(top->left);   //pushing left first so that it goes to bottom
            }
            if(top->right!=NULL){
                s2.push(top->right);  //pushing right latter so that it goes to top
            }
            
            
            cout<<top->data<<" ";
        }
        cout<<endl;  //printing a line after a stack gets empty

        while(!s2.empty()){
            top = s2.top();
            s2.pop();
            
            if(top->right!=NULL){
                s1.push(top->right);  //pushing right first so that it goes to bottom
            }
            if(top->left!=NULL){
                s1.push(top->left);   //pushing left latter so that it goes to top
            }
            
            cout<<top->data<<" ";  
        }
        cout<<endl;  //printing a line after a stack gets empty
        
    } 
    
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    
	if(root == NULL){
        return NULL;      //edge case
    }

    if(root->left == NULL && root->right == NULL){
        delete root->left;
        delete root->right;          //base case
        delete root;
        return NULL;
    }
    
    if(root->left != NULL){
        root->left = removeLeafNodes(root->left);
    }
    if(root->right != NULL){
        root->right = removeLeafNodes(root->right);
    }
    return root;

}

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;      //edge case
    }
    
    
    if(root->left!=NULL && root->right==NULL){
        cout<<root->left->data<<" ";          //small cal
    }
    if(root->left==NULL && root->right!=NULL){
        cout<<root->right->data<<" ";       //small cal
    }
    

    if(root->left!=NULL){
        printNodesWithoutSibling(root->left);    //rec
    }
    if(root->right!=NULL){
        printNodesWithoutSibling(root->right);   //rec
    }
    
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	if(n==0){
        return NULL;  //base case
    }
    
    int mid = (n-1)/2;
    BinaryTreeNode<int>* lr = constructTree(input,mid);
    BinaryTreeNode<int>* rr = constructTree(input+mid+1,n-mid-1);
    
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(input[mid]);
    root->left = lr;
    root->right = rr;
    return root;
    
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	
    if(root == NULL){
        return NULL;   //base case
    }
    
    Node<int>*Lroot = new Node<int>(root->data);
    
    Node<int>* lr = constructLinkedList(root->left);
    Node<int>* rr = constructLinkedList(root->right);
    
    if(lr==NULL){
        Lroot->next = rr;
        return Lroot;
    }
    
    Node<int>* temp = lr;
    while(temp->next!=NULL){
        temp = temp->next;    //instead of this a better sol is to return a pair of tail and head
    }
    
    temp->next = Lroot;
    Lroot->next = rr;
    return lr;
    
}
//something wrong-_-
/*pair<Node<int>*,Node<int>*> constructLinkedList1(BinaryTreeNode<int>* root) {
	
    if(root == NULL){
        pair<Node<int>*,Node<int>*> p;
        p.first = NULL;
        p.second = NULL;
        return p;   //base case
    }
    
    Node<int>*Lroot = new Node<int>(root->data);
    Node<int>*Ltail = Lroot;
    
    pair<Node<int>*,Node<int>*> lr = constructLinkedList1(root->left);
    pair<Node<int>*,Node<int>*> rr = constructLinkedList1(root->right);
    
    if(lr.first==NULL){
        Lroot->next = rr.first;
        Ltail = rr.second;
        pair<Node<int>*,Node<int>*> p;
        p.first = Lroot;
        p.second = Ltail;
        return p;
    }
    
    lr.second->next = Lroot;
    Lroot->next = rr.first;
    Ltail = rr.second;
    pair<Node<int>*,Node<int>*> p;
    p.first = lr.first;
    p.second = Ltail;
    return p;
    
}*/

void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{
    int ind1 = 0, ind2 = 0;
    
    for(int i = 0;i<size1+size2;i++){
        if(ind1<size1&&ind2<size2){
        	if(arr1[ind1]>arr2[ind2]){
            	ans[i] = arr2[ind2];
            	ind2++;
        	}
        	else{
            	ans[i] = arr1[ind1];
            	ind1++;
        	}
        }
        else if(ind1==size1){
            ans[i] = arr2[ind2];
            ind2++;
        }
        else{
            ans[i] = arr1[ind1];
            ind1++;
        }
    }
}
void mergeSort(int input[], int size){
	
    if(size==1||size==0){
        return;
    }
    int mid = (size-1)/2;
    mergeSort(input,mid+1);
    mergeSort(input+(mid+1),size-mid-1);
    int arr[size];
    merge(input,mid+1,input+(mid+1),size-mid-1,arr);
    for(int i = 0;i<size;i++){
        input[i]= arr[i];
    }
        return;
}
void treeToArray(BinaryTreeNode<int> * root,vector<int>&arr){
    if(root==NULL){
        return;
    }
    arr.push_back(root->data);
    treeToArray(root->left,arr);
    treeToArray(root->right,arr);

}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int> arr;
    treeToArray(root,arr);
    
    int te[arr.size()];
    for(int i = 0;i<arr.size();i++){
        te[i] = arr.at(i);            //copying vector to array
    }

    mergeSort(te,arr.size());  //sorting array

    int i = 0,j = arr.size()-1;
    while(j>i){
        if(te[i]+te[j] == sum){
            cout<<te[i]<<" "<<te[j]<<endl;
            j--;
            i++;
        }
        else if(te[i]+te[j] > sum){
            j--;
        }
        else if(te[i]+te[j] < sum){
            i++;
        }
    }
}

//Least Common Ancestor
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root == NULL){
        return -1;
    }
    if(root->data == a){
        return a;               //base case
    }
    else if(root->data == b){
        return b;
    }
    
    int ansL = getLCA(root->left,a,b);   //rec call
    int ansR = getLCA(root->right,a,b);
    
    if(ansL == -1 && ansR != -1){
        return ansR;
    }
    if(ansR == -1 && ansL != -1){     //small calc
        return ansL;
    }
    if(ansL == -1 && ansR == -1){
        return -1;
    }
    if(ansL != -1 && ansR != -1){
        return root->data;
    }
     
}

BinaryTreeNode<int> *buildTreeHelper(int *postorder, int postStart, int postEnd, int *inorder,
                                     int inStart, int inEnd){
    if (postStart > postEnd || inStart > inEnd){
        return NULL;
    }
    int rootVal = postorder[postEnd];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);
    // Find parent element index from inorder array
    int k = 0;
    for (int i = inStart; i <= inEnd; i++){
        if (rootVal == inorder[i]){
            k = i;
            break;
        }
    }
    root->left = buildTreeHelper(postorder, postStart, postStart + k - inStart - 1, inorder,
                                 inStart, k - 1);
    root->right = buildTreeHelper(postorder, postStart + k - inStart, postEnd - 1, inorder, k + 1, inEnd);
    return root;
}
BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder, int inLength){
    int postStart = 0;
    int postEnd = postLength - 1;
    int inStart = 0;
    int inEnd = inLength - 1;
    return buildTreeHelper(postorder, postStart, postEnd, inorder, inStart, inEnd);
}
