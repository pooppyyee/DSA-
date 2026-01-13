//SLLWithFunctions.cpp 
#include<iostream>
using namespace std;

struct Person
{
    int pId, pAge;
    string pName;
    Person* pNext; 
};

//Define the functions
//Version 1 of addToFront
// void addToFront(Person** head, Person* student)
// {
//     student->pNext = *head; 
//     *head = student;        
// }

//Version 2 of addToFront
// void addToFront(Person*& head, Person* student)
// {
//     student->pNext = head; 
//     head = student;        
// }

//Version 3 of addToFront
Person* addToFront(Person* head, Person* student) // Return Type: Person*
/*Reason: Since 'head' is passed by value (Person* head), the original 'head' pointer in 'main' cannot be modified directly. 
The function must return the new head address, and 'main' must use an assignment (head = addToFront(...)) to update the list's state.*/ 
{  
    student->pNext = head; // link new node to the current head
    head = student;        // update head to point to the new node
    return head;
}

void addToBack(Person* head, Person* student)
{
    Person* current = head;
    while(current ->pNext != NULL)
    { 
        current = current->pNext;
    }
    current->pNext = student;

}

void deleteAtFront(Person** head)
{
    *head = (*head)->pNext;
} 

void deleteAtBack(Person* head)
{
    Person* current = head;
    while(current->pNext->pNext != NULL)
    {
        current = current->pNext; //let it be NULL
    }
    current->pNext = NULL;
} 

void addAtNPosition(Person* head, Person* student)
{
    int n = 3;
    Person* current = head;
    for(int loop = 1; loop < n-1; loop++)
    {
        current = current->pNext; //move current to the next node
    }
    student->pNext = current->pNext; //student pNext from NULL to ah_hock
    current->pNext = student;
}

void deleteAtNPositon(Person* head)
{
     //f) Delete at position n
    int n = 3;
    Person* current = head;
    for(int loop = 2; loop < n; loop++)
    {
        if(current->pNext != NULL)
        {
            current = current->pNext;
        }
    }
    current->pNext = current->pNext->pNext;
}

void displayList(Person* head)//* refers to the pointer variable "head"
{
    Person* current = head; //current is temporary, it has no value outside this function
    while(current !=NULL)
    {
        cout << "Name : " << current->pName << endl << "Age : "
             << current->pAge << endl << "Id : "
             << current->pId << endl;
        //move current to the next node
        current = current->pNext; //current moving
    }
}



int main()
{
    //declare 3 Person nodes, ali, muthu, ah_hock that are part of a linked list
    Person* ali = new Person;
    Person* muthu = new Person;
    Person* ah_hock = new Person;

    //declare head & current as Person nodes => helper nodes, not part of the linked list
    Person* head;
    Person* current;
   
    //assign head & current to ali
    head = current = ali;

    //populate (add data) the nodes with the appropriate data - for pId, pAge, pName
    ali->pId = 123;
    ali->pName = "Ali";
    ali->pAge = 21;

    muthu->pId = 124;
    muthu->pName = "Muthu";
    muthu->pAge = 20;

    ah_hock->pId = 125;
    ah_hock->pName = "Ah Hock";
    ah_hock->pAge = 23;

    //link all the nodes
    ali->pNext = muthu;
    muthu->pNext = ah_hock;
    ah_hock->pNext = NULL;

    //----------------------------------------------------------------
    //create a new Person and details
    Person* student = new Person;
    student->pId = 888;
    student->pName = "Harry";
    student->pAge = 99;
    student->pNext = NULL;
    
    //e) Add a new node to n position
    //STEP 1: make sure there are at least 2 other nodes in the list
    Person* emi = new Person;
    Person* bonnie = new Person;
    //STEP 2: Initialise values for the 2 other nodes
    *emi = {765, 23, "Emi"};
    *bonnie = {354, 22, "Bonnie"};
    //STEP 3: Connect the 2 other emi bonnie to the current linked list
    ah_hock->pNext = emi;
    emi->pNext = bonnie;
    bonnie->pNext = NULL;
    
    //============FUNCTION CALLS================= 

    //addToFront (Version 1)
        //addToFront(&head, student);
    //addToFront (Version 2)
        //addToFront(head, student);
    //addToFront (Version 3)
        head = addToFront(head, student);

    //addToBack(head, student);
    //deleteAtFront(&head);
    //deleteAtBack(head);
    //deleteAtNPositon(head);
    //addAtNPosition(head,student);
    displayList(head);
}