//LinkedList.cpp SAQ (15m)
//Modified - add new person at the front
//at the end, at n position, delete an existing node at the front, at the end and at n position
#include<iostream>
using namespace std;

//structure definition should be global
struct Person
{
    int pId, pAge;
    string pName;
    Person* pNext; //connector
};

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
    // //----------------------------------------------------------------
    // //a) Add student to the front of the linked list
    // student->pNext = head; 
    // head = student; //let head point the first node to student
    //----------------------------------------------------------------
    
    //b) Delete first node of the linked list (no student Harry added)
    //head = head->pNext; //let head point to the second node, ignore first node ALI
    //----------------------------------------------------------------
    
    //c) Add student to the end of the linked list
    // while(current->pNext != NULL)
    // { 
    //     current = current->pNext;
    // }
    // current->pNext = student;
    //----------------------------------------------------------------
    
    //d) Delete last node at the end 
    // while(current->pNext->pNext != NULL)
    // {
    //     current = current->pNext; //let it be NULL
    // }
    // current->pNext = NULL;
    //----------------------------------------------------------------
    
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
    //STEP 4: Add the new node to n position
    // int n = 3;
    // current = head;
    // for(int loop = 1; loop < n-1; loop++)
    // {
    //     current = current->pNext; //move current to the next node
    // }
    // student->pNext = current->pNext; //student pNext from NULL to ah_hock
    // current->pNext = student;
    //----------------------------------------------------------------
    
    //f) Delete at position n
    int n = 3;
    current = head;
    for(int loop = 2; loop < n; loop++)
    {
        if(current->pNext != NULL)
        {
            current = current->pNext;
        }
    }
    current->pNext = current->pNext->pNext; //skip the node at n position
    //----------------------------------------------------------------


    //display all the values in the linked list using head in a while loop
    current = head; //b4 display, tell current to start with head
    while(current !=NULL)
    {
        cout << "Name : " << current->pName << endl << "Age : "
             << current->pAge << endl << "Id : "
             << current->pId << endl;
        //move current to the next node
        current = current->pNext; //current moving
    }

    
}