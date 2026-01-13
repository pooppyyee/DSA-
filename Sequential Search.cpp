/*LAQ
1 - Write C++ program to do a sequential search
for the price based on the following arrays.*/
/*Note that the values are not sorted*/
 
#include <iostream>
using namespace std;

bool search(double list[], int size, double s)
{
	for (int i = 0; i < size; i++)
	{
		if(list[i] == s)
		{
			return true;
		}
	} return false;
}

int main ()
{
    double prices[5] = {23.70, 73.80, 22.00, 15.20, 80.40};
    double pSearch; //this value will be determined by the user
	cout << "Enter the price to search: ";
	cin >> pSearch;

	search(prices, 5, pSearch) ? cout << pSearch << " is found in the array." << endl 
	                           : cout << pSearch << " is not found in the array." << endl;

	return 0;
}

 



