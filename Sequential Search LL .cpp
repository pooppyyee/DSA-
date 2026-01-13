/*
2 - Write C++ program to do a sequential search for the price of the item
based on the given structure and lists provided.
*/
#include <iostream>
using namespace std;

struct Item
{
	int itemId;
	string itemName;
	double itemPrice;
};

struct Node 
{
    Item data;
    Node* next;
};

bool search(Node* head, double p)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data.itemPrice == p)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main ()
{
    Item itemList[5] = {{123, "Colgate", 12.30}, {234, "Drinho Packets", 30.00},
		    {328, "Top Washing Liquid", 34.20}, {378, "Softlan ", 8.00},
			{322, "Cooking Oil", 24.80}};
    double price = 24.80;
    
    //convert array to linked list
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < 5; i++)
    {
        Node* newNode = new Node;
        newNode->data = itemList[i];
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    search(head, price) ? cout << price << " is found" << endl
                        : cout << price << " is not found" << endl;

}

 


