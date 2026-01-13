/*AdjacencyMatrix.cpp*/
/*AM: store data in 2D array and use this array to find distance b/w 2 vertices */
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//To use the for_each function: will read the string and convert
//to uppercase - "transform" -> single letter   
//               "for_each" -> string (airport/location name)

int const NOLINK = -2;
int const NOLOOP = -1;
int const NO_AIRPORTS = 5; //array size = no_vertices
  
/*a) Declare and initialize an array to list the vertices in the graph	(5 marks)*/
string airport[NO_AIRPORTS] = {"KUL", "BKK", "SIN", "PEK", "HKG"};

/*b) Declare and initialize an array to store the weights (distances) between the locations / 
	 vertices for the graph												(10 marks)*/

int graph[NO_AIRPORTS][NO_AIRPORTS] = {{-1, 758, 186, 2765, 1851}, {758, -1, 881, 2063, 1051}, 
                                       {186, 881, -1, 2793, 1596}, {2765, 2063, 2793, -1, -2},
                                       {1851, 1051, 1596, -2, -1}};
                            
int main()
{
 
int to, from;
string placeTo;
string placeFrom;
 
cout << "\nEnter departure : KUL, BKK, SIN, PEK, HKG :" << endl;
cin >> placeFrom;  

for_each(placeFrom.begin(), placeFrom.end(), [](char & c) {
c = ::toupper(c);
});
 
for (from = 0; from < NO_AIRPORTS; from++)
{
	if (placeFrom == airport[from])
		break;
}
cout << "\nEnter destination : KUL, BKK, SIN, PEK, HKG :" << endl;
cin >> placeTo;
 
for_each(placeTo.begin(), placeTo.end(), [](char & c) {
c = ::toupper(c);});
 
for (to = 0; to < NO_AIRPORTS; to++)
{
	if (placeTo == airport[to])
		break;
}
cout << "Flight is from " << airport[from] << " to " << airport[to] << endl;
 
/*c)	Write the selection control statement to display the distance between the vertices / locations
	as required by the user. If there is no connection between the vertices / locations, display
	an appropriate message. If there is no connection between a particular vertex / location with 
	itself, display the appropriate message
																							(10 marks)*/
                                                                                            
if(graph[from][to] != NOLINK)
{
    if(graph[from][to] != NOLOOP)
    {
        cout << "Distance is " << graph[from][to] << endl;
    }else {
        cout<< "The plane does not fly back to its own departure" << endl;
    }
}else {
    cout << "There is no flight to your destination" << endl;
}
    
}
 