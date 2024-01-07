#include<iostream>
using namespace std;
#include<vector>
#include<queue>
template<typename T>
class TreeNode{  // it stores some data and list of its children
    public:
    T data;   // for storing data
    vector<TreeNode*> children;   //for storing list of children

    // vector<TreeNode<T>*> children;   //same as above line. If we dont specify datatype it automatically assumes to be T

    TreeNode(T data){
        this->data = data;
    }

    ~TreeNode(){
        for(int i = 0;i<root->children.size();i++){
            deleteTree(root->children[i];)         //post order traversal
        }
    }

};


/*it prints many trees in same way 
  if output is 1 2 3 then the tree may be 1->2->3  or  1->(2 , 3)
*/
void printTree(TreeNode<int>*root){
    if(root==NULL){
        return;    //edge case and NOT a base case for recursion
    }

    cout<<root->data<<endl;
    for(int i = 0;i<root->children.size();i++){ //it automatically works as base case
        printTree(root->children[i]);          // when we dont have any child it simply returns
    }
}


/* prints a unique tree.
  It prints parent and its children 
  */
void printTree2(TreeNode<int>*root){
    if(root==NULL){
        return;              //edge case and NOT a base case for recursion
    }

    cout<<root->data<<":";
    for(int i = 0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0;i<root->children.size();i++){
        printTree2(root->children[i]);     //it automatically works as base case
    }                                      // when we dont have any child it simply returns
}


// giving input is difficult and can confuse the user.For giving input the user must know recursion
TreeNode<int>* takeInput(){
    int rootdata;
    cout<<"Enter data ";
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);  //creating root and putting data

    cout<<"Enter number of children of "<<rootdata<<endl;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        TreeNode<int>*child = takeInput();  //taking input for each child
        root->children.push_back(child);    //connecting each child to root
    }
    return root;
}


// taking input level wise. Easy to give input
TreeNode<int>* takeInputLevelWise(){
    int rootdata;
    cout<<"Enter root data ";
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);  //creating root and putting data

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"enter number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;

        for(int i = 0;i<numChild;i++){
            int data;
            cout<<"enter data for "<<i<<"th node"<<endl;
            cin>>data;
            TreeNode<int>* child = new TreeNode<int>(data);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingNode;  //stores nodes which themselves and there children have not been printed
    pendingNode.push(root);  //pushing root to queue
    
    while(pendingNode.size()!=0){
        
        TreeNode<int>*front = pendingNode.front();
        pendingNode.pop();                               //storing front of queue and poping it
        cout<<front->data<<":";  //printing that node
        
        for(int i = 0;i<front->children.size();i++){
            pendingNode.push(front->children[i]);
            cout<<front->children[i]->data;   //printing front's children
            
            if(i<front->children.size()-1){
                cout<<",";  //print ',' only if it is not the last child
            }
            
        }
        cout<<endl;
    } 
}

int numNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    
    int ans = 1;
    for(int i = 0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int>* root) {

    if(root==NULL){
        return 0;    //edge case and not base case
    }
    
    int sum = 0;
    for(int i = 0;i<root->children.size();i++){
        sum+=sumOfNodes(root->children[i]);
    }
    return sum+(root->data);
}

int getHeight(TreeNode<int>* root) {
    if(root==NULL){
        return 0;    //edge case and not base case
    }
    
    int h = 0;
    
    for(int i = 0;i<root->children.size();i++){
        int smallh = getHeight(root->children[i]);
        
        if(h<smallh){
            h = smallh;
        }
        
    }
    return h+1;
}

bool isPresent(TreeNode<int>* root, int x) {
    if(root->data==x){
        return true;     //edge case not base case
    }
    
    for(int i = 0;i<root->children.size();i++){
        
        bool b = isPresent(root->children[i],x);
        
        if(root->children[i]->data==x){
            return true;
        }
        else if(b==true){
            return true;
        }
    }
    return false;
}

void printAtLevelK(TreeNode<int>*root,int k){
    if(root==NULL){
        return;                 //edge case
    }
    
    if(k==0){
        cout<<root->data;   //base case
        return;
    }

    for(int i = 0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}

int getLeafNodeCount(TreeNode<int>* root) {
    
    if(root->children.size()==0){
        return 1;                 //base case
    }

    int totalLeaf = 0;
    for(int i = 0;i<root->children.size();i++){
        int childLeaf = getLeafNodeCount(root->children[i]);
        totalLeaf+=childLeaf;
    }

    return totalLeaf;
    
}

void printPostOrder(TreeNode<int>* root) {
    if(root==NULL){
        return;     //edge case
    }
    
    for(int i = 0;i<root->children.size();i++){
        printPostOrder(root->children[i]);
    }
    
    cout<<root->data<<" "; 
    
}

void printPreOrder(TreeNode<int>* root) {
    if(root==NULL){
        return;     //edge case
    }

    cout<<root->data<<" "; 

    for(int i = 0;i<root->children.size();i++){
        printPostOrder(root->children[i]);
    }
    
}

void deleteTree(TreeNode<int>*root){
    //application of post order traversal
    //method 2 can be using destructor in which we can use post order traversal
    for(int i = 0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root == NULL){
        return root;
    }
    
    TreeNode<int>* max = root;
    for(int i = 0;i<root->children.size();i++){
        TreeNode<int>*maxChild = maxDataNode(root->children[i]);
        if(maxChild->data>max->data){
            max = maxChild;
        }
    }
    return max;
}


