//Index Calculation Codes
#include<iostream>
#include<string>
using namespace std;
/*a) Declare a constant identifier for the total no of the nodes, including the null characters*/
const int SIZE = 16;
/*b) Declare and intialize the indCalTree using the details from the Index Calculation table*/
char indCalTree [SIZE] = {'\0', '+', '-', '6', '*', '/', '\0', '\0', '9', '5', '8', '4', '\0', '\0', '\0', '\0'};

/*d) Define the following functions*/
//i. the leftChild(int index) function
int leftChild (int index)
{
    return index * 2;
}
//ii. the rightChild(int index) function 
int rightChild (int index)
{
    return (index * 2)+1;
}
//iii. the isValid function that checks if the index exists in the tree and there is a value in the tree[index]
bool isValid (int index)
{
    return (index < SIZE && indCalTree[index]); 
    //RETURN 1 OR TRUE IF INDEX < 16 & NON NULL CHARACTER IN THE NODE OF THE TREE
}
//iv. the display function that accepts a string */
void display (char data) //REPRESENTS PARENT 
{
    cout << data << "\t";
}
/*ii. the inorder function that accepts the integer variable, index. This function is a recursive function*/
void inorder(int index) //LPR
{
    if (isValid(index))
    {
        inorder(leftChild(index));
        display(indCalTree[index]);
        inorder(rightChild(index));
    }
}
/*iii. the preorder function that accepts the integer variable, index. This function is a recursive function*/
void preorder(int index)
{
    if (isValid(index))
    {
        display(indCalTree[index]);
        preorder(leftChild(index));
        preorder(rightChild(index));
    }
}
/*iv. the postorder function that accepts the integer variable, index. This function is a recursive function*/
void postorder(int index)
{
    if (isValid(index))
    {
        postorder(leftChild(index));
        postorder(rightChild(index));
        display(indCalTree[index]);
    }
}

int main()
{
	cout << "\nInorder traversal : ";
	inorder(1);
	//Repeat the above for preorder and postorder traversal
    cout << "\nPreorder traversal : ";
	preorder(1);
    cout << "\nPostorder traversal : ";
	postorder(1);
}