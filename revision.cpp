#include <iostream>
using namespace std;

// void showHi()
// {
//     cout << "Hi World\n";
// }

// void showName(string name)
// {
//     cout << "name is: "<< name << endl;
// }

// int findSum(int a, int b)
// {
//     int sum = a+b;
//     return sum;
// }

// double showPrice()
// {
//     double price;
//     cout << "Enter price: " << endl;
//     cin >> price;
//     return price;
// }

// int main()
// {
    
//     showHi();
//     showName("yee");

//     int a = 10, b = 20;
//     cout<< "Sum is: " << findSum(a,b) << endl;

//     double sPrice = showPrice();
//     cout << "Price is: " << sPrice << endl;
    
// }

struct Station
{
    int sId;
    string sName;
    double sTime;
    Station * sNext;
};

int main()
{
    Station *subang = new Station;
    Station *glenmarie = new Station;
    Station *ss15 = new Station;

    Station* head;
    Station* current;

    head =current = glenmarie;

    subang->sId = 11;
    subang->sName = "Subang Jaya";
    subang->sTime = 2.0;

    glenmarie->sId = 10;
    glenmarie->sName = "CGC Glenmarie";
    glenmarie->sTime = 3.0;

    ss15->sId = 12;
    ss15->sName = "SS15";
    ss15->sTime = 1.9;

    glenmarie->sNext=subang;
    subang->sNext=ss15;
    ss15->sNext=NULL;

    Station* midvalley = new Station;
    midvalley->sId = 8;
    midvalley->sName = "Abdullah Hukum";
    midvalley->sTime = 20.00;
    midvalley->sNext=NULL;

    Station* shit = new Station;
    shit->sId = 7;
    shit->sName = "Shit";
    shit->sTime = 10.50;
    shit->sNext=NULL;

    // //put midvalley to first 
    // midvalley->sNext = head;
    // head = midvalley;

    // //IGNORE 1st one
    // head = head->sNext;

    //put shit to last
    while(current->sNext != NULL)
    {
        current = current->sNext;
    }
    current->sNext = shit;

    // //delete last shit
    // while(current->sNext->sNext != NULL)
    // {
    //     current = current->sNext;
    // }
    // current->sNext = NULL;

    Station * jurong = new Station;
    Station * harbour = new Station;

    *jurong = {99, "Jurong", 999.99};

    *harbour = {88, "้ร้้้ก", 888.88};

    //add after shit
    shit->sNext = jurong;
    jurong->sNext = harbour;
    harbour->sNext = NULL;

    //glenmarie->subang->ss15\->shit->jurong->harbour
    //add midvalley b/w ss15, shit
    int n = 4;
    current = head;
    for(int loop=1; loop < n-1 ; loop++)
    {
        current = current -> sNext;
    }
    midvalley->sNext = current-> sNext; //midvalley -> shit
    current->sNext = midvalley; // ss15 -> midvalley

    //remove jurong
    //glenmarie->subang->ss15->midvalley->shit(5)\->jurong->harbour
    int m = 5;
    current = head;
    for(int loop=1; loop < m; loop++)
    {
        if(current->sNext!=NULL)
        {
            current = current->sNext;
        }
    } 
    current->sNext = current->sNext->sNext;
    //display
    current = head;
    while(current != NULL)
    {
        cout << "Station ID: "<<current->sId << endl << current->sName << endl << current->sTime << " minutes" << endl; 
        current = current->sNext;
    }

    
}