/*Queue with Linked List*/
#include<iostream>
#include<string>
using namespace std;
 
struct Student
{
	int studId;
	string studName;
	int studAge;
	Student *nxtStudent;
};
 
void displayList(Student *front)
{
	/*a) Write the function definition for displayList that will 
		display all values of the list*/
    Student* current = front;
    cout << "Queue contents (from front to rear):" << endl;
    while(current != NULL)
    {
        cout << "Name is " << current->studName << endl;
        cout << "ID is " << current->studId << endl;
        cout << "Age is " << current->studAge << endl;
        cout << "------------------------" << endl;
        current = current->nxtStudent;
    }
}
void enqueue(Student *nStudent, Student *&front, Student *&rear)
{
	/*b) Write the function definition for enqueue that will 
		add nStudent to the rear of the list */
    //If queue is empty, both front and rear point to new node
    if (front == NULL)
    {
        front = nStudent;
        rear = nStudent;
    }
    else
    {
        rear->nxtStudent = nStudent; //link new node at the end of queue
        rear = nStudent; //update rear to new node
    }
}
void dequeue(Student *&front)
{
	/*c) Write the function definition for dequeue that will 
		display the front value of the list and remove it.*/
    Student* temp = front; //temp points to node to be deleted
    if (temp == NULL) return;
    cout << "Dequeued student:" << endl;
    cout << "Name is " << temp->studName << endl;
    cout << "ID is " << temp->studId << endl;
    cout << "Age is " << temp->studAge << endl;

    front = front->nxtStudent; //change front to next node
}
 
int main()
{
	Student *front, *rear, *newStudent;
	int option;
 
	front = NULL;
	rear = NULL;
 
	do
	{
		cout << "\nEnter option : 1 to enqueue, 2 to dequeue, 3 to display, any other value to exit :" << endl;
		cin >> option;
		if (option == 1 || option == 2 || option == 3)
		{
			switch (option)
			{
			case 1:
			{
				newStudent = new Student;
				cout << "Enter id, age and name of student " << endl;
				cin >> newStudent->studId >> newStudent->studAge;
				cin.ignore();
				getline(cin, newStudent->studName, '\n');
				newStudent->nxtStudent = NULL;
 
				enqueue(newStudent, front, rear);
				break;
			}
			case 2:
			{
				if (front == NULL)
				{
					cout << "Nothing to delete" << endl;
				}
				else
				{
					dequeue(front);
				}
				break;
			}
			case 3:
			{
				if (front == NULL)
					cout << "Nothing to show" << endl;
				else
					displayList(front);
				break;
			}
			}//end of switch
 
		}
		else
		{
			cout << "\nYou have chosen to exit " << endl;
			break;
		}
 
	} while (option >= 1 && option <= 3);
 
 
}