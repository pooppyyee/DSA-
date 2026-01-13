//BPTreeLL.cpp Implementation using Linked List
#include<iostream>
using namespace std;
 
/*a) Define a struct called Node that has operand (can be either character or string), 2 pointer variables
of Node - to store the address of the leftChild and the rightChild*/
struct BTreeNode
{
    char operand;
    BTreeNode* left;
    BTreeNode* right;
};

/*b) Define a function called initialNewNode() that passes op as the operator / operand. The pointer of Node is created and initialized, the operator / operand is assigned to the new node and the leftChild and rightChild are initialized to NULL. The new node is returned to the main*/
//initialize, create new node
BTreeNode* initialNewNode(char op)
{
    BTreeNode* temp = new BTreeNode();
    temp->operand = op;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/*c) Define a function called display()- parent that accepts a character / string variable to represent the operator / operand and this will be displayed in the function.*/
void display(char op)
{
    cout << op;
} 

/*d) Define the following functions, preorder(), postorder() and inorder(). The pointer node is passed to the function. As it is a recursive function, if the node is not NULL the displayNode(), and the respective functions are called according to the sequence. */
void preorder(BTreeNode * node)
{
    if (node) //if node not NULL
    {
        //parent
        display(node->operand);
        preorder(node->left);
        preorder(node->right);
    }
} 
void postorder(BTreeNode * node)
{
    if (node) //if node not NULL
    {
        //parent
        postorder(node->left);
        postorder(node->right);
        display(node->operand);
    }
} 
void inorder(BTreeNode * node)
{
    if (node) //if node not NULL
    {
        //parent
        inorder(node->left);
        display(node->operand);
        inorder(node->right);
    }
} 
int main()
{ /*Building the tree :
e) Declare the pointer variables for the internal nodes, including the root. */
BTreeNode* root, *parent1, *parent2, *parent3;
//struct BTreeNode root, parent1, parent2, parent3; //what this line for?

/*f) use the internal nodes to build the tree and pass the operator / operands according to the design of the tree. 
As each new node is created, call the initialNewNode() function and pass the necessary argument.*/

//build tree
root = initialNewNode('+');
root->left = initialNewNode('-');
root->right = initialNewNode('6');

parent1 = root->left;
parent1->left = initialNewNode('*');
parent1->right = initialNewNode('/');

parent2 = parent1->left;
parent2->left = initialNewNode('9');
parent2->right = initialNewNode('5');

parent3 = parent1->right;
parent3->left = initialNewNode('8');
parent3->right = initialNewNode('4');

cout << "\nPreorder traversal : \t";
preorder(root);
/*g) Repeat the above for inorder and postorder traversals.*/
cout << "\nInorder traversal : \t";
inorder(root);
cout << "\nPostorder traversal : \t";
postorder(root);
}