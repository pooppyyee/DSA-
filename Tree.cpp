/*
Draw the Binary Parse Tree for the following formula.
Build the Index Referencing Table.
(a * b) + (c * d) - e
*/
 
/*Implementation of Index Referencing*/
#include<iostream>
#include<string>
using namespace std;
 
const int SIZE = 9;
 
/*1 - Define a structure called Node that has a character variable called data and 2 int variables to store leftIndex and rightIndex.*/
 struct Node
 {
    char data;
    int left, right;
 };
/*2 - Declare and initialise the BinaryParseTree using the data in the
Index Referencing Table */
Node binaryParseTree[SIZE] = {{'+', 1, 2}, {'-', 3, 4}, {'6', -1, -1}, 
                              {'*', 5, 6}, {'/', 7, 8}, {'9', -1, -1}, 
                              {'5', -1, -1}, {'8', -1, -1}, {'4', -1, -1}}; 

/*3 - Write the function definition for */
/*a) - display() that accepts a character / a string but does not return
any values. The function merely displays the value in the argument*/
void display(char data)  //normally called when traversal is a parent
{
    cout << data << "\t";
} 

/*b) - inorder() that accepts an integer value, index, but does not return any values. The function is a recursive function.
 Within the function the index is evaluated to ensure it is not -1. 
 If it is not -1, it is not a leaf and therefore it calls itself by passing the index of the left / right child. 
 As it in inorder(), the sequence is LPR*/
void inorder(int index) //pass tree inside the bracket using index number
{
    if(index != -1) //not leaf, is parent, can continue
    {
        inorder(binaryParseTree[index].left);  //left child
        display(binaryParseTree[index].data);  //parent
        inorder(binaryParseTree[index].right); // right child
    }
}
/*c) - preorder() - similar to inorder but the sequence is PLR */
void preorder(int index) //pass tree inside the bracket using index number
{
    if(index != -1) //not leaf, is parent, can continue
    {
        display(binaryParseTree[index].data);  //parent
        preorder(binaryParseTree[index].left);  //left child
        preorder(binaryParseTree[index].right); // right child
    }
}

/*d) - postorder() - similar to postorder but the sequence is LRP */
void postorder(int index) //pass tree inside the bracket using index number
{
    if(index != -1) //not leaf, is parent, can continue
    {
        postorder(binaryParseTree[index].left);  //left child
        postorder(binaryParseTree[index].right); // right child
        display(binaryParseTree[index].data);  //parent
    }
}
int main()
{
    cout << "\nIn Order Traversal" << endl;
    inorder(0); //call inorder (pass the root)
    cout << "\nPre Order Traversal" << endl;
    preorder(0); //call preorder (pass the root)
    cout << "\nPost Order Traversal" << endl;
    postorder(0); //call postorder (pass the root)
}