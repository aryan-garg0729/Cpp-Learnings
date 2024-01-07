#include"BST.h"

BinaryTreeNode<int>* constructTree(int *input, int n) {
	if(n==0){
        return NULL;
    }
    
    int mid = (n-1)/2;
    BinaryTreeNode<int>* lr = constructTree(input,mid);
    BinaryTreeNode<int>* rr = constructTree(input+mid+1,n-mid-1);
    
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(input[mid]);
    root->left = lr;
    root->right = rr;
    return root;
}

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
        te[i] = arr.at(i);
    }
    mergeSort(te,arr.size());
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

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root == NULL){
        return -1;
    }
    if(root->data == a){
        return a;
    }
    else if(root->data == b){
        return b;
    }
    
    if (root->data < a && root->data < b) {
        int ansR = getLCA(root->right,a,b);
		return ansR;
	} 
    else if (root->data > a && root->data > b) {
        int ansL = getLCA(root->left,a,b);
		return ansL;
	}
    
    int ansR = getLCA(root->right,a,b);
    int ansL = getLCA(root->left,a,b);
    
    if(ansL == -1 && ansR != -1){
        return ansR;
    }
    if(ansR == -1 && ansL != -1){
        return ansL;
    }
    if(ansL == -1 && ansR == -1){
        return -1;
    }
    if(ansL != -1 && ansR != -1){
        return root->data;
    }
    
    
}

class ans{
    public:
    int minimum;
    int maximum;
    int height;
    bool bst;
    ans(){
        minimum = 0;
        maximum = 0;
        height = 0;
        bst = false;
    }
};
ans isBST(BinaryTreeNode<int> *root){
    if(root == NULL){
        ans a;
        a.bst = true;
        a.minimum = 9999;
        a.maximum = -9999;
        return a;
    }
    
    ans L = isBST(root->left);
    ans R = isBST(root->right);
    
    ans a;
    a.maximum = max(max(L.maximum,R.maximum),root->data);
    a.minimum = min(min(L.minimum,R.minimum),root->data);
    if(L.bst && R.bst && root->data>L.maximum && root->data<R.minimum){
        a.bst = true;
        a.height = max(L.height,R.height) + 1;
        return a;
    }
    
    a.bst = false;
    a.height = max(L.height,R.height);
    return a;
    
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    
    ans a = isBST(root);
    return a.height;
    
}

int replaceWithLargerNodesSum(BinaryTreeNode<int> *root,int sum){
    if(root == NULL){
        return 0;
    }
    
    int R = replaceWithLargerNodesSum(root->right,sum);
    int L = replaceWithLargerNodesSum(root->left,R+sum+root->data);
    int rd = root->data;
    root->data = R+sum+root->data;
    return L+R+rd;
    
}

void helper(BinaryTreeNode<int> *root, int k,string p) {
    if(root == NULL){
        return;
    }
    
    p = p + to_string(root->data) + " ";
    
    helper(root->left,k-root->data,p);
    helper(root->right,k-root->data,p);
    
    if(root->left==NULL && root->right == NULL && k == root->data){
        cout<<p<<endl;
    }
    
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    string p;
    helper(root,k,p);
    
}
