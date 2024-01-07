#include"_tree.h"
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if(root == NULL){
        return root;    //edge case
    }
    
    TreeNode<int>* ans = root;
    int sum = 0;
    
    for(int i = 0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    
    for(int i = 0;i<root->children.size();i++){
        TreeNode<int>* child = maxSumNode(root->children[i]);
        int sum1 = 0;
    	for(int i = 0;i<child->children.size();i++){
        	sum1+=child->children[i]->data;
    	}
        if(sum<sum1){
            sum = sum1;
            ans = child;
        }
    }
    
    return ans;
    
}

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1==NULL||root2==NULL){
        return false;                 //edge case
    }
    
    if(root1->data!=root2->data){
        return false;
    }
    else if(root1->children.size()!=root2->children.size()){
        return false;
    }
    
    for(int i = 0;i<root1->children.size();i++){
        bool b = areIdentical(root1->children[i],root2->children[i]);
        if(!b){
            return false;
        }
    }
    
    return true;
    
}

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    
    if(root==NULL){
        return NULL;   //edge case
    }

    TreeNode<int>*ans = NULL;
    int ansdata = 9999;

    for(int i = 0;i<root->children.size();i++){
        TreeNode<int>*smallans = getNextLargerElement(root->children[i],x);

        if(smallans!=NULL && smallans->data<ansdata){
            ans = smallans;
        	ansdata = ans->data;
        }
    }
    
    if(root->data>x && root->data<ansdata){
        return root;
    }
    return ans;
    
}

void replaceWithDepthValue(TreeNode<int>*root,int k){  //put value of k = 0 intially
    if(root == NULL){
        return;      //edge case
    }
    root->data = k;
    for(int i = 0;i<root->children.size();i++){
    	replaceWithDepthValue(root->children[i],k+1);
    }
}

int getLargeNodeCount(TreeNode<int>* root, int x) {
    
    if(root == NULL){
        return 0;      //edge case
    }
    int count = 0;
    for(int i = 0;i<root->children.size();i++){
        int smallCount = getLargeNodeCount(root->children[i],x);
        count += smallCount;
    }
    if(root->data>x){
        count++;
    }
    return count;

}
