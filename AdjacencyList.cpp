#include<iostream>
using namespace std;
const int KUL = 0;
const int SIN = 1;
const int BKK = 2;
const int PEK = 3;
const int HKG = 4;

 
struct Edge;
/*a) Write the structure definition for Country that represents the vertices
                                                                    (3 marks)*/                                                   
struct Country //vertex
{
    string nameAirport;
    Edge *nxtD;
};

/*b) Write the structure definition for Edge that represents the edges with 
     the weight, called distance.
                                                                    (4 marks)*/
                                                               
struct Edge
{
    int distance;
    Country *dest;
    Edge *nxt;
};
 
/*c)  Declare and initialise the array of pointer variables that store the names
      of the vertices and each pointer will be initialized to NULL. //nxtD = NULL     (5 marks)*/
Country airportList[5] = {{"KUL", NULL}, {"SIN", NULL}, {"BKK", NULL}, {"PEK", NULL}, {"HKG", NULL}};
 
/*d)  Write the function definition for setLinks that assigns the distance to the 
      edge that is related to each pair of vertices.
                                                                (10 marks)*/
void setLinks(Country *from, Country *to, int dist)
{
    Edge *e = new Edge;
    e->distance = dist;
    e->dest = to;
    e->nxt = from->nxtD;
    from->nxtD = e;
}
 
/*e)  Write the function definition for buildGraph that calls the setLinks
      function and builds the graph by associating a distance to each pair of 
      vertices                                                  (10 marks)*/
void buildGraph()
{
    setLinks(&airportList[KUL], &airportList[SIN], 186);
    setLinks(&airportList[KUL], &airportList[BKK], 758);
    setLinks(&airportList[KUL], &airportList[HKG], 2765);
    setLinks(&airportList[KUL], &airportList[PEK], 1851);
    setLinks(&airportList[SIN], &airportList[KUL], 186);
    setLinks(&airportList[SIN], &airportList[BKK], 881);
    setLinks(&airportList[SIN], &airportList[HKG], 2793);
    setLinks(&airportList[SIN], &airportList[PEK], 1596);
    setLinks(&airportList[BKK], &airportList[SIN], 881);
    setLinks(&airportList[BKK], &airportList[KUL], 758);
    setLinks(&airportList[BKK], &airportList[HKG], 2063);
    setLinks(&airportList[BKK], &airportList[PEK], 1051);
    setLinks(&airportList[HKG], &airportList[KUL], 2765);
    setLinks(&airportList[HKG], &airportList[BKK], 2063);
    setLinks(&airportList[HKG], &airportList[SIN], 2793);
    setLinks(&airportList[PEK], &airportList[KUL], 1851);
    setLinks(&airportList[PEK], &airportList[BKK], 1051);
    setLinks(&airportList[PEK], &airportList[SIN], 1596);
}
 
/*f)  Write the function definition, calculateDistance() that calcualates 
      the distance between 2 vertices and returns its value.
                                                    (6 marks) */
int calculateDistance(Country *from, Country *to)
{
 
	Edge* temp = from->nxtD;
	while (temp->dest != to)
	{
		temp = temp->nxt;
	}
	if (temp->dest->nameAirport == to->nameAirport)
		return temp->distance;
	else
		return 0;
 
}
 
int main()
{
    int fromIndex, toIndex;
    Country *frm, *to;
    int jarak;
    buildGraph();
    cout << "Select Source : " << endl
<< KUL << " for KUL " << endl
<< SIN << " for SIN " << endl
<< BKK << " for BKK " << endl
<< PEK << " for PEK " << endl
<< HKG << " for HKG " << endl;
    cin >> fromIndex;
    cout << "Select destination : " << endl
<< KUL << " for KUL " << endl
<< SIN << " for SIN " << endl
<< BKK << " for BKK " << endl
<< PEK << " for PEK " << endl
<< HKG << " for HKG " << endl;
    cin >> toIndex;

    frm = &airportList[fromIndex];
    to = &airportList[toIndex];
    cout << "From " << frm->nameAirport << " to " << to->nameAirport << endl;
    jarak = calculateDistance(frm, to);
    if(jarak != 0)
    {
        cout << "It is " << jarak << " km " << endl;
    }
    else
    {
        cout << " No direct route from " << frm->nameAirport << " to " << to->nameAirport << endl;
    }


}
 