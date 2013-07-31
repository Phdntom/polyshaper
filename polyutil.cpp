struct Node{
	int i;
	int j;
};

void print_avail(bool **avail,int N_site){
	for(int i = 0; i < N_site; i++) {
		for(int j = 0; j < 2*N_site-1; j++)
			cout << avail[i][j] << " ";
		cout << endl;
	}
}

bool IsValid(Node neighbor, int const N_site) {
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

int polypletNeighbors(Node v,Stack<Node> &stack,bool **avail,int const N_site) {
	Node n;
	int num_added = 0;
	n.i = v.i;
	n.j = v.j+1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i+1;
	n.j = v.j+1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i+1;
	n.j = v.j;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i+1;
	n.j = v.j-1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i;
	n.j = v.j-1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i-1;
	n.j = v.j-1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i-1;
	n.j = v.j;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i-1;
	n.j = v.j+1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	return num_added;
}

int polyominoNeighbors(Node v,Stack<Node> &stack,bool **avail,int const N_site) {
	Node n;
	int num_added = 0;
	n.i = v.i;
	n.j = v.j+1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i+1;
	n.j = v.j;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i;
	n.j = v.j-1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i-1;
	n.j = v.j;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	return num_added;
}

int polyhexNeighbors(Node v,Stack<Node> &stack,bool **avail,int const N_site) {
	Node n;
	int num_added = 0;
	n.i = v.i;
	n.j = v.j+1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i+1;
	n.j = v.j+1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i+1;
	n.j = v.j;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i;
	n.j = v.j-1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i-1;
	n.j = v.j-1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i-1;
	n.j = v.j;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	return num_added;
}

void explore(Stack<Node> &stack,bool **avail,Node *path,int depth,
 int const N_site,	int &graph_count,
 int polyshapeNeighbors(Node,Stack<Node> &,bool**,int const)) {
	//precondition stack is NOT empty
	Node v = stack.Pop();
	path[depth] = v;
	depth++;

	if(depth == N_site) {
		//cout << "Path\n";
		//for(int l = 0; l < depth; l++)
		//	cout << "(" << path[l].i << "," << path[l].j << ") ";
		graph_count++;
		//cout << endl;
	}
	else {
		int num_added = polyshapeNeighbors(v,stack,avail,N_site);
		Stack<Node> low_stack = stack;

		while( !low_stack.IsEmpty() ) {
			explore(low_stack,avail,path,depth,N_site,graph_count,polyshapeNeighbors);
		}//explore the path along the top of the stack

		Node a;
		for(int neighbors = 0; neighbors < num_added; neighbors++) {
			a = stack.Pop();
			avail[a.i][a.j] = 1;
		}//for neighbors added this level

	}//else

}//void explore, recursive

int generatePolyShape(int const N_site,
 int polyshapeNeighbors(Node,Stack<Node> &,bool**,int const) ){

	bool **avail = new bool*[N_site];
	for(int i = 0; i < N_site; i++) {
		avail[i] = new bool[2*N_site-1];
		for(int j = 0; j < 2*N_site-1; j++) {
			avail[i][j] = 1;
		}
	}
	for(int j = 0; j < N_site-1; j++) {
		avail[0][j] = 0;//depicted as an X below
	}
	/*
			<---- 2*N_site-1 --->
		^	   X X ... X S 0 0 ... 0
		|	   0 0 ... 0 0 0 0 ... 0 
	N_site 0 0 ... . . . . ... 0 
		|    . . ... . . . . ... . 
		v	   0 0 ... . . . . ... 0

			X: not allowed
			0: available
			S: starting cell for all graphs 

	*/
	Node *path = new Node[N_site];
	Stack<Node> stack;

	Node start;
	start.i = 0;
	start.j = N_site-1;
	//start node, S, has coordinates (0,N_site-1)
	stack.Push(start);
	//initial condition place node S on the empty stack
	avail[0][N_site-1] = 0;
	//mark S as unavailable

	int graph_count = 0;
	int depth = 0;
	//there are zero graphs to start and the length of the exploration is zero

	explore(stack,avail,path,depth,N_site,graph_count,polyshapeNeighbors);

	return graph_count;
}//generatePolyShape
