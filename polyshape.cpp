
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "Stack.cpp"
#include "polyutil.cpp"


int main(int argc, char* argv[]) {

	cout << "  This program generates polyshapes.\n";
    int N_site = atoi(argv[1]);
    cout << N_site << endl;


//polyominoes
    cout << "\nominoes: " << generatePolyShape(N_site,polyominoNeighbors);
//polyplets
    cout << "\nplets: " << generatePolyShape(N_site,polypletNeighbors);
//polyhexes
    cout << "\nhex: " << generatePolyShape(N_site,polyhexNeighbors);
//polyiamonds
    //int count = generatePolyShape(N_site,polyiamondNeighbors);

    cout << endl;
return 0;
}//main
