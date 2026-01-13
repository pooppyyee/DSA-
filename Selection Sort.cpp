/*-----------------------------------------------------------------------------------------------------------
Sorting Algorithm
Using the same structure and list above, write a full program to sort the items based on the prices using
b) Selection Sort
*/

#include <iostream>
using namespace std;

struct Item
{
	int itemId;
	string itemName;
	double itemPrice;
};
 
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

int main()
{
    Item itemList[5] = {{123, "Colgate", 12.30}, {234, "Drinho Packets", 30.00},
		    {328, "Top Washing Liquid", 34.20}, {378, "Softlan ", 8.00},
			{322, "Cooking Oil", 24.80}};

    int i, j, min;
    for(i = 0; i < 4; i++)
    {
        min = i;
        for(j = i+1; j < 5; j++)
        {
            if(itemList[j].itemPrice < itemList[min].itemPrice)
            {
                min = j;
            }
        } swap(itemList[min], itemList[i]);
    }

    for (Item il: itemList)
    {
        cout << il.itemId << ", " << il.itemName << ", "<< il.itemPrice << endl;
    }



}


