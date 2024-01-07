#include<iostream>
using namespace std;
#include<queue>
#include "_tree.h"

int main(){
    // TreeNode<int> t(2); //static allocation

    // //dynamic allocation
    // TreeNode<int>*root = new TreeNode<int>(1);
    // TreeNode<int>*node1 = new TreeNode<int>(2);
    // TreeNode<int>*node2 = new TreeNode<int>(3);

    // root->children.push_back(node1);      //         |1|   ---> root
    // root->children.push_back(node2);      /*        /   \      */
                                             //      |2|   |3|    ---->children
    

    //      Tree functions
    // printTree(root);
    // printTree2(root);

   { TreeNode<int>* t = takeInput();
    printTree2(t);
    delete t;  //destructor gets called
/*Enter data 1
Enter number of children of 1
3
Enter data 2
Enter number of children of 2
2
Enter data 5
Enter number of children of 5
0
Enter data 6
Enter number of children of 6
0
Enter data 3
Enter number of children of 3
1
Enter data 7
Enter number of children of 7
0
Enter data 4
Enter number of children of 4
1
Enter data 8
Enter number of children of 8
0

the tree is:-
1:2,3,4,
2:5,6,
5:
6:
3:7,
7:
4:8,
8:
*/}

}