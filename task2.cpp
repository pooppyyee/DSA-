#include <iostream>
#include <string>
using namespace std;

struct Product {
    int pId;
    string pDesc;
    double pPrice;
};

const int SIZE = 6;

int main(){
    Product food[SIZE];

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

    Product* pFood = food; //pointer to the first array element

    //display food using pointer
    cout << "Product ID " << "\t" << "Product Description" << "\t" << "Product Price" << endl;
    cout << "----------------------------------------------------------" << endl;
    for(int i=0; i<SIZE; i++){
        cout << pFood[i].pId << "\t\t" << (pFood+i)->pDesc << "\t\t\t" << (pFood+i)->pPrice << endl;
    }

}