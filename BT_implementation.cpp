#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include"BT.h"

int main(){

    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);   //creation
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;  //connections

    printTree2(root);*/

    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTree2(root);

    // cout<<numNodes(root);

    preOrderTraversal(root);
    inorderTraversal(root);
    postOrderTraversal(root);

    // printLevelWise(root);


    return 0;
}