//Binary Search Tree Using Linked List
 
#include <iostream>
#include <string>
using namespace std;
 
//C++ program to demonstrate insert operation in binary search tree and do a 
//binary search algorithm.
 
struct BinaryTreeStudent
{
 
	int id, age;
	string fName;
	string lName;
 
	BinaryTreeStudent *left, *right;
 
};
 
 
/*Write the function definition for addNewStudent*/
 
BinaryTreeStudent* addNewStudent(int sId, int sAge, string firstName, string lastName)
{
    BinaryTreeStudent* temp = new BinaryTreeStudent();
    temp -> id = sId;
    temp -> age = sAge;
    temp -> fName = firstName;
    temp -> lName = lastName;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}
 
/*Write the function definition called insert to insert a new node with given id in the Binary Tree 
using recursion*/
 
BinaryTreeStudent* insert(BinaryTreeStudent* listStudents, int sId, int sAge, string firstName, string lastName)
{
 
	if (listStudents == NULL) //if no root
			return addNewStudent(sId, sAge, firstName, lastName);
 
	if (sId < listStudents->id) //s.id change to id
			listStudents->left = insert(listStudents-> left, sId, sAge, firstName, lastName);
	else if (sId > listStudents->id)
	listStudents->right = insert(listStudents-> right, sId, sAge, firstName, lastName);
 
	return listStudents;
 
}
 
void display(BinaryTreeStudent*s)
{
    cout << "\nID: " << s->id << "\nName: " << s->fName << " " << s->lName << "\nAge: " << s->age << endl;
}
 
 
void inorder(BinaryTreeStudent* root)
{
	if (root != NULL)
	{
        inorder(root->left);
        display(root);
        inorder(root->right);
	}
}
 
/*Recursive binary searching through the Binary Tree */
 
BinaryTreeStudent* search(BinaryTreeStudent* root, int key)
{
 
	if (root == NULL || root->id == key) //s.id change to id
			return root;
 
	if (root->id < key)
		return search(root->right, key);
 
 
	return search(root->left, key);
 
}
 
int main()
{
 
	BinaryTreeStudent* root = NULL;
 
	BinaryTreeStudent* result = NULL;
 
	int input;
 
	root = insert(root, 50, 51, "Ali", "Baba");
	insert(root, 30, 25, "Ahmad", "Jaguh");
	insert(root, 20, 34, "Muthu", "Mohhan");
	insert(root, 40, 21, "Robbin", "Houston");
	insert(root, 70, 32, "Alex", "Johnson");
	insert(root, 60, 19, "Peter", "Parker");
	insert(root, 80, 20, "Issac", "Davidson");
 
	/*Display the records in sequence using the inorder function */
 
	inorder(root);
	cout << "\nEnter id: ";
	cin >> input;
	result = search(root, input);
 
	if (result != NULL)
		display(result);
	else
		cout << "\nRecord not found." << endl;
 
}