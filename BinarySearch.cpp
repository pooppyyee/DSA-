#include <iostream>
using namespace std;
const int SIZE = 9;
int main()
{
    int sArray[SIZE] = {18, 36, 39, 48, 54, 63, 80, 88, 100};
    int valueToSearch = 15;

    int first = 0, last = SIZE - 1, mid = 0;
    do {
        mid = (first + last) / 2;
        if (sArray[mid] == valueToSearch)
        {
            cout << "Found " << valueToSearch << " at position " << mid << endl;
            return 0; //stop the program if found number
        } else
        {
            if (valueToSearch < sArray[mid])
            {
                last = mid - 1;
            }else if (valueToSearch > sArray [mid])
            {
                first = mid + 1;
            }
        }
    }while (first <= last);
    
    //if number not found: 
    cout << valueToSearch << " is not found in the array." << endl;
    
}