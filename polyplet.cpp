
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

#include "Stack.cpp"

#include "polyutil.cpp"


void print_avail(bool **,int);



void explore(Stack<Node> &stack,bool **avail,
		Node *path,int depth,int const N_site,int &counter) {
	//precondition stack is NOT empty
	Node v = stack.Pop();
	path[depth] = v;
	depth++;

	if(depth == N_site) {
		//cout << "Path\n";
		//for(int l = 0; l < depth; l++)
		//	cout << "(" << path[l].i << "," << path[l].j << ") ";
		counter++;
		//cout << endl;
	}
	else {
		int num_added = polypletNeighbors(v,stack,avail,N_site);
		//print_avail(avail,N_site);
		Stack<Node> low_stack = stack;

		while( !low_stack.IsEmpty() ) {
			explore(low_stack,avail,path,depth,N_site,counter);
		}//explore the path along the top of the stack

		Node a;
		for(int neighbors = 0; neighbors < num_added; neighbors++) {
			a = stack.Pop();
			avail[a.i][a.j] = 1;
		}//for neighbors added this level

	}//else

}//void explore, recursive

int generatePolyShape(int const N_site,Graph *graph_list);
int main(int argc, char* argv[]) {

	cout << "This generates polyominoes that need ony be connected via corners.\n";

	if(argc !=2) {
		cout << "Usage: polyplet.e #cells\n";
		return 1;
	}
	else {
		int N_site = atoi(argv[1]);
		cout << "We will now generate polyplets with " << N_site << " cells.\n";
		Graph *graph_list;
		int count = generatePolyShape(N_site,graph_list);

		cout << "The number of polyshapes with " << N_site << " cells is " << count << endl;
	}//else

return 0;
}//main

int generatePolyShape(int const N_site,Graph *graph_list){
	bool **avail = new bool*[N_site];
	for(int i = 0; i < N_site; i++) {
		avail[i] = new bool[2*N_site-1];
		for(int j = 0; j < 2*N_site-1; j++) {
			avail[i][j] = 1;
		}
	}
	for(int j = 0; j < N_site-1; j++) {
		avail[0][j] = 0;
	}
	Node *path = new Node[N_site];
	Stack<Node> stack;

	Node start;
	start.i = 0;
	start.j = N_site-1;

	stack.Push(start);
	avail[0][N_site-1] = 0;

	int graph_count = 0;
	int depth = 0;

	explore(stack,avail,path,depth,N_site,graph_count);

}//generatePolyShape

void print_avail(bool **avail,int N_site){
	for(int i = 0; i < N_site; i++) {
		for(int j = 0; j < 2*N_site-1; j++)
			cout << avail[i][j] << " ";
		cout << endl;
	}
}

