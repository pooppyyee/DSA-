/*Stack with Linked List*/
#include<iostream>
#include<string>
using namespace std;
//This structure is a linked list structure bcs of "Student* nxtStudent;"(LINE 12)

struct Student
{
	int studId;
	string studName;
	int studAge;

	Student* nxtStudent;
};
//a)
void display(Student *stu) //stu = head in LL
{
	cout << "Name is " << stu->studName << endl;
	cout << "ID is " << stu->studId << endl;
	cout << "Age is " << stu->studAge << endl;
}
void displayList(Student* top)
{
	//display in loop
	Student* current = top;
	cout << "Stack contents (from top to bottom):" << endl;
	while (current != NULL)
	{
		cout << "------------------------" << endl;
		display(current);
		current = current->nxtStudent;
	}
	cout << "------------------------" << endl;
}
bool isEmpty(Student *stu)
{
	//LL never full - if top = null, return true
    return(stu == NULL);
}
//& = call by reference - return top & bottom
void push(Student* nStudent, Student*& top, Student*& bottom)
{
	//insert at top
    nStudent->nxtStudent = top;
    top = nStudent;
	// if stack was empty, bottom points to new node
	if (bottom == NULL)
	{
		bottom = nStudent;
	}
}
//display data to be deleted - call the display a) change address of top
void pop(Student*& top, Student* bottom)
{
	if(top == NULL)
	{return;}
	
	Student* temp = top; //temp points to node to be deleted
	display(temp); 

	top = top->nxtStudent; //change top to next node
	//if stack becomes empty, reset bottom
	if(top == NULL)
	{
		bottom = NULL;
	}
	delete temp; //free memory
}

int main()
{
	Student* top, *bottom, *newStudent;
	int option;

	top = NULL; //no existing list in stack
	bottom = NULL; 
	newStudent = NULL;
	
	do
	{
		cout << "\nEnter option : 1 to push, 2 to pop, 3 to display, any other value to exit :" << endl;
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

				push(newStudent, top, bottom); //1st time top & bottom are null
				break;
			}
			case 2:
			{
				if (isEmpty(top)) //use function isEmpty() instead of "top = NULL"
				{
					cout << "Nothing to delete" << endl;
				}
				else
				{
					pop(top, bottom);
				}
				break;
			}
			case 3:
			{
				if (!isEmpty(top)) //use function isEmpty() instead of "top = NULL"
				{
					displayList(top);
				}
				else
				{
					cout << "Nothing to show" << endl;
				}
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

	while (!isEmpty(top))
	{
		pop(top, bottom);
	}

}

