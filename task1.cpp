#include <iostream>
#include <string>
using namespace std;

struct Product {
    int pId;
    string pDesc;
    double pPrice;
};

const int SIZE = 6;

int main() {
    Product food[SIZE];
    char choice;
    int id;
    //ask user to input and store values
    for(int i = 0; i < SIZE; i ++) {
        cout << "Enter product ID: " <<endl;
        cin >> food[i].pId;
        cin.ignore();
        cout << "Enter product description: " <<endl;
        getline(cin,food[i].pDesc,'\n');
        cout << "Enter product price: " <<endl;
        cin >> food[i].pPrice;
    }
    
    //ask user if want to edit price
    do {
        cout << "Do you want to edit the price of any product? (press Y for yes)" << endl;
        cin >> choice;
        if (choice =='y' || choice == 'Y'){
            cout << "Enter the product ID of the product you want to edit: " << endl;
            cin >> id;

            bool found = false;
            for(int i = 0; i < SIZE; i++) {
                if (food[i].pId == id) {
                    cout << "Enter the new price: " << endl;
                    cin >> food[i].pPrice;
                    found = true;
                    break;
                } else {
                    cout << "Product ID not found." << endl;
                }
            }
        } else { 
            break;
        }
    }while (choice == 'y' || choice == 'Y');

    /* 
    cout << "Enter prices of all items: " << endl;
    for (int i = 0; i<SIZE; i++) {
        cout << "Product " << food[i].pId ;
        cin >> food[i].pPrice;   
    }
    */

    //display all products
    cout << "Product ID " << "\t" << "Product Description" << "\t" << "Product Price" << endl;
    for(Product f:food) {
        cout << f.pId << "\t\t" << f.pDesc << "\t\t\t" << f.pPrice << endl;
    }
}

