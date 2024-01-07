#include<iostream>
using namespace std;
#include<vector>
#include<queue>

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;
    BinaryTreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL; 
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

void printTree1(BinaryTreeNode<int>*root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<endl;
    printTree1(root->left);
    printTree1(root->right);
}

void printTree2(BinaryTreeNode<int>*root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printTree2(root->left);
    printTree2(root->right);
}

void printLevelWise(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return;
    }
    
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        if(front!=NULL){
        cout<<front->data<<":";
        if(front->left!=NULL){
        	cout<<"L:"<<front->left->data<<",";
            pendingNodes.push(front->left);
    	}
        else{
            cout<<"L:"<<"-1,";
		}
    	if(front->right!=NULL){
        	cout<<"R:"<<front->right->data;
            pendingNodes.push(front->right);
    	}
        else{
            cout<<"R:"<<"-1";
		}
        cout<<endl;
        
        
        }
    }
}

BinaryTreeNode<int>* takeInput1(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;

    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootData);
    root->left = takeInput1();
    root->right = takeInput1();
    return root;
}

BinaryTreeNode<int>* takeInputLevelWise(){
    queue<BinaryTreeNode<int>*> pendingNodes;
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;

    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BinaryTreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;

        if(leftChildData!=-1){
            BinaryTreeNode<int>*Child = new BinaryTreeNode<int>(leftChildData);
            front->left = Child;
            pendingNodes.push(Child);
        }

        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>*Child = new BinaryTreeNode<int>(rightChildData);
            front->right = Child;
            pendingNodes.push(Child);
        }
        
    }
    return root;
}

int numNodes(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return numNodes(root->left)+numNodes(root->right)+1;
}

int height(BinaryTreeNode<int>* root) {
    
    if(root == NULL){
        return 0;
    }
    
    // int h1 = height(root->left);
    // int h2 = height(root->right);
    // if(h1>h2){
    //     return h1+1;
    // } 
    // else{
    //     return h2+1;
    // }

    return 1+max(height(root->left),height(root->right));

}

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    
    if(root == NULL){
        return false;
    }
    bool b1,b2;
    if(root->data==x){
        return true;
    }
    if(root->left!=NULL){
    	b1 = isNodePresent(root->left,x);
    }
    if(root->right!=NULL){
        b2 = isNodePresent(root->right,x);
    }
    return b1||b2;
     
}

/*this function prints in inorder fashion 
  i.e. L root R
For the Btree:-
(1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1)
1 : L2 R3
2 : L4 R5
4 :
5 :
3 : L6 R7
6 : L8 R9
8 :
9 :
7 :
we get :-
4 2 5 1 8 6 9 3 7 
*/
void inorderTraversal(BinaryTreeNode<int>*root){
    if(root == NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);

}

/*this function prints in preorder fashion 
  i.e. root L R
For the Btree:-
(1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1)
1 : L2 R3
2 : L4 R5
4 :
5 :
3 : L6 R7
6 : L8 R9
8 :
9 :
7 :
we get :-
1 2 4 5 3 6 8 9 7 
*/
void preOrderTraversal(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right); 
    
}

/*this function prints in postorder fashion 
  i.e. L R root
For the Btree:-
(1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1)
1 : L2 R3
2 : L4 R5
4 :
5 :
3 : L6 R7
6 : L8 R9
8 :
9 :
7 :
we get :-
4 5 2 8 9 6 7 3 1  
*/
void postOrderTraversal(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return;
    }
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
    
}

//not efficient.. TC = O(n*h)
int diameter1(BinaryTreeNode<int>*root){
    if(root == NULL){
        return 0;
    }
    int option1 = height(root->left)+height(root->right);
    int option2 = diameter1(root->left);
    int option3 = diameter1(root->right);

    return max(option1,max(option2,option3));

}

//better approach.. TC = O(n) 
pair<int,int> heightDiameter(BinaryTreeNode<int>*root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> leftans = heightDiameter(root->left);
    pair<int,int> rightans = heightDiameter(root->right);
    pair<int,int> ans;
    int lh = leftans.first;
    int ld = leftans.second;
    int rh = rightans.first;
    int rd = rightans.second;

    int height = max(rh,lh)+1;
    int diameter = max(max(ld,rd),lh+rh);

    ans.first = height;
    ans.second = diameter;

    return ans;

}

vector<int>* getRootToNodePath(BinaryTreeNode<int>*root,int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>*leftOutput = getRootToNodePath(root->left,data);
    if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int>*rightOutput = getRootToNodePath(root->right,data);
    if(rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }

}

