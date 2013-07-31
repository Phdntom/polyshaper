
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

template<class T>
class Stack{
	int size;
	T array[1000];

 public:
	Stack( ){size = 0;};
	void Push(T item);
	T Pop();
	bool IsEmpty();
	Stack<T>& operator =(const Stack<T>& rightSide);
};

template<class T>
void Stack<T>::Push(T item){
	if(size < 1000)
		array[size] = item;
	else
		cout << "Stack overflow\n";
	size++;
}

template<class T>
T Stack<T>::Pop(){
	if(size > 0) {
		size--;
		return array[size];
	}
	else
		cout << "Stack underflow\n";
}

template<class T>
bool Stack<T>::IsEmpty(){
	return (size == 0);
}

template<class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& aStack)
{
	for(int i = 0; i < aStack.size; i++)
		array[i] = aStack.array[i];
	size = aStack.size;

}//= operator

struct Node{
	int i;
	int j;
};

/*
struct Graph{
	int node_count;
	Node *node;
};
*/

void print_visited(bool **,int);

bool IsValid(Node neighbor, int const N_site) {
	//it's already been visited
	//it's in the bounds of the grid
	if( neighbor.j >=2*N_site-1 )
		return 0;
	if( neighbor.j < 0 )
		return 0;
	if( neighbor.i >=N_site )
		return 0;
	if( neighbor.i < 0 )
		return 0;
	return 1;
}//bool IsValid

void explore(Stack<Node> &stack,bool **visited,bool **avail,
		Node *path,int depth,int const N_site,int &counter) {

	Node v = stack.Pop();
	path[depth] = v;
	depth++;
	//print_visited(visited,N_site);

	if(depth == N_site) {
		cout << "Path\n";
		for(int l = 0; l < depth; l++)
			cout << "(" << path[l].i << "," << path[l].j << ") ";
		counter++;
		cout << endl;
	}
	else {
		Node n;
		int num_added = 0;
		n.i = v.i;
		n.j = v.j+1;
		if( IsValid(n,N_site) && avail[n.i][n.j] /*&& !visited[n.i][n.j]*/ ) {
			stack.Push(n);
			avail[n.i][n.j] = 0;
			num_added++;
		}
		n.i = v.i+1;
		n.j = v.j;
		if( IsValid(n,N_site) && avail[n.i][n.j] /*&& !visited[n.i][n.j]*/ ) {
			stack.Push(n);
			avail[n.i][n.j] = 0;
			num_added++;
		}
		n.i = v.i;
		n.j = v.j-1;
		if( IsValid(n,N_site) && avail[n.i][n.j] /*&& !visited[n.i][n.j]*/ ) {
			stack.Push(n);
			avail[n.i][n.j] = 0;
			num_added++;
		}
		n.i = v.i-1;
		n.j = v.j;
		if( IsValid(n,N_site) && avail[n.i][n.j] /*&& !visited[n.i][n.j]*/ ) {
			stack.Push(n);
			avail[n.i][n.j] = 0;
			num_added++;
		}
		print_visited(avail,N_site);
		cout << endl;

		Stack<Node> low_stack = stack;

		while( !low_stack.IsEmpty() ) {
			explore(low_stack,visited,avail,path,depth,N_site,counter);
		}

		Node a;
		for(int neighbors = 0; neighbors < num_added; neighbors++) {
			a = stack.Pop();
			avail[a.i][a.j] = 1;
		}//for neighbors added this level

	}//else

}//void explore, recursive


int main(int argc, char* argv[]) {

	int N_site = atoi(argv[1]);
	cout << N_site << endl << endl;

	bool **visited = new bool*[N_site];
	bool **avail = new bool*[N_site];
	for(int i = 0; i < N_site; i++) {
		visited[i] = new bool[2*N_site-1];
		avail[i] = new bool[2*N_site-1];
		for(int j = 0; j < 2*N_site-1; j++) {
			visited[i][j] = 0;
			avail[i][j] = 1;
		}
	}
	for(int j = 0; j < N_site-1; j++) {
		visited[0][j] = 1;
		avail[0][j] = 0;
	}

	cout << " start exploring node 0\n";
	int graph_count;
//	Graph *graph_list = new Graph[10000];

	Node start;
	start.i = 0;
	start.j = N_site-1;
	int depth = 0;

	Node *path = new Node[N_site];

	Stack<Node> stack;
	stack.Push(start);

	avail[0][N_site-1] = 0;

//	print_visited(visited,N_site);
//	cout << endl;
//	print_visited(avail,N_site);
//	cout << endl;

	int counter = 0;
	explore(stack,visited,avail,path,depth,N_site,counter);
	cout << counter << endl;

return 0;
}//main

void print_visited(bool **visited,int N_site){
	for(int i = 0; i < N_site; i++) {
		for(int j = 0; j < 2*N_site-1; j++)
			cout << visited[i][j] << " ";
		cout << endl;
	}
}
