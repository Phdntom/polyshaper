
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "Stack.cpp"
#include "polyutil.cpp"
void showMenu() {
		cout << "\tUsage: polyshape.e #cells #shapetype\n";
		cout << "\t#cells range: 1 to 13.\n";
		cout << "\t#shapetypes:\n";
		cout << "\t (1) polyomino: squares that share a side.\n";
		cout << "\t (2) polyplet: squares that share a corner or a side.\n";
		cout << "\t (3) polyhex: hexagons that share a side.\n";
		cout << "\t (4) polyiamond: triangles that share a side.\n"; 
}

int main(int argc, char* argv[]) {

	cout << "  This program generates polyshapes.\n";
	if(argc !=3) {
		showMenu();
		return 1;
	}
	else {
		int N_site = atoi(argv[1]);
		if( N_site < 1 || N_site > 13) {
			cout << "\tYour #cells was not a valid number.\n";
			showMenu();
			return 1;
		}
		if( atoi(argv[2]) == 1) {
			cout << "We will now generate polyominoes with " << N_site << " cells.\n";
			int count = generatePolyShape(N_site,polyominoNeighbors);
			cout << "The number of polyominoes with " << N_site << " cells is " << count << endl;
		}
		else if( atoi(argv[2]) == 2){
			cout << "We will now generate polyplets with " << N_site << " cells.\n";
			int count = generatePolyShape(N_site,polypletNeighbors);
			cout << "The number of polyplets with " << N_site << " cells is " << count << endl;
		}
		else if( atoi(argv[2]) == 3){
			cout << "We will now generate polyhexes with " << N_site << " cells.\n";
			int count = generatePolyShape(N_site,polyhexNeighbors);
			cout << "The number of polyhexes with " << N_site << " cells is " << count << endl;
		}
		else if( atoi(argv[2]) == 4){
			cout << "We can't generate polyiamonds yet\n";
			//cout << "We will now generate polyiamonds with " << N_site << " cells.\n";
			//int count = generatePolyShape(N_site,polyiamondNeighbors);
			//cout << "The number of polyiamond with " << N_site << " cells is " << count << endl;
		}
		else {
			cout << "No valid shape specified.\n";
			showMenu();
		}
	}//else

return 0;
}//main
