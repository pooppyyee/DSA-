//C++ program to demonstrate inserting data in a single linked list
// and display the data
#include <iostream>
#include <string>
using namespace std;

struct Student 
{
    int id, age;
    string fName;
    string lName;
    Student * nxtStudent;
};

Student * createStudentNode (int id, int age, string fName, string lName)
{
    Student * temp = new Student();
    temp -> id = id;
    temp -> age = age;
    temp -> fName = fName;
    temp -> lName = lName;
    temp -> nxtStudent = NULL;
    return temp;
}

void displayList (Student * s) //s = current
{
    while (s != NULL)
    {
        cout << "\nID: " << s->id << "\nName: " << s->fName << " " << s->lName << "\nAge: " << s->age << endl;
        s = s->nxtStudent;
    }

}

Student * addToEnd (Student* head, int id, int age, string fName, string lName)
{
    Student * newNode = createStudentNode(id, age, fName, lName);

    if (head == NULL)  //if list empty
        return newNode;
    
    Student * s = head;
    while(s -> nxtStudent != NULL)
    {
        s = s -> nxtStudent;
    }
    s -> nxtStudent = newNode;

    return head; //important line
}

int main ()
{
    //Add a list of student data in a linked list format. Use the functions given above.
    Student * head = NULL;

    head = addToEnd(head, 100, 20, "ali", "baba");
    addToEnd(head, 200, 22, "abu", "chicken");
    addToEnd(head, 300, 24, "hello", "kitty");

    displayList(head);

}