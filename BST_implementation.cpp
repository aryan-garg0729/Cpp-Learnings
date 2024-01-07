#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include"BST.cpp"

int main(){

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);   //creation
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;  //connections

    return 0;
}