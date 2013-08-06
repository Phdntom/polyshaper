struct Node{
    /*'

    
    '*/
	int i;
	int j;
    bool color;
};

void print_avail(bool **avail, int N_site)
{
	for(int i = 0; i < N_site; i++) {
		for(int j = 0; j < 2*N_site-1; j++)
			cout << avail[i][j] << " ";
		cout << endl;
	}
}

bool IsValid( Node neighbor, int const N_site )
{
    /*'
    Parameters
    ----------
    neighbor:   Node, proposed as valid part of grid with members (i,j)
    N_site:     int, marking grid boundary

    Returns
    -------
    TRUE:       if valid cell in grid
    FALSE:      if NOT valid cell in grid

    '*/
	if( neighbor.j >=2*N_site-1 )
		return 0;
	if( neighbor.j < 0 )
		return 0;
	if( neighbor.i >=N_site )
		return 0;
	if( neighbor.i < 0 )
		return 0;

	return 1;
}// bool IsValid

int polypletNeighbors( Node v, Stack<Node> &stack,
                       bool **avail, int const N_site )
{
    /*'
    Parameters
    ----------
    v:          Node, around which we find neighbor cells
    stack:      LIFO list, holds all prev added neighbors
    avail:      bool, TRUE when a cell can be added
    N_site:     int, defines size of grid variables and max depth
    
    Returns
    -------
    num_added:  the count of the number of neighbors added in this call

    DETAILS
        Adds nearest and next nearest cells of a square lattice to the
        current stack. The order is defined below beginning with cell 0.
        Cells which are not available are skipped.
        . . . . .
        . 5 6 7 .
        . 4 v 0 .
        . 3 2 1 .
        . . . . .
    '*/

	Node n;
	int num_added = 0;

	n.i = v.i;                                  // right
	n.j = v.j+1;
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i+1;                                // lower
	n.j = v.j+1;                                // right
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i+1;                                // lower
	n.j = v.j;                                  //
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i+1;                                // lower
	n.j = v.j-1;                                // left
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i;                                  //
	n.j = v.j-1;                                // left
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i-1;                                // upper
	n.j = v.j-1;                                // left
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i-1;                                // upper
	n.j = v.j;                                  //
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}
	n.i = v.i-1;                                // upper
	n.j = v.j+1;                                // right
	if( IsValid(n,N_site) && avail[n.i][n.j] ) {
		stack.Push(n);
		avail[n.i][n.j] = 0;
		num_added++;
	}

	return num_added;
}

int polyominoNeighbors( Node v, Stack<Node> &stack,
                        bool **avail, int const N_site )
{
    /*'
    Parameters
    ----------
    v:          Node, around which we find neighbor cells
    stack:      LIFO list, holds all prev added neighbors
    avail:      bool, TRUE when a cell can be added
    N_site:     int, defines size of grid variables and max depth
 
    Returns
    -------
    num_added:  the count of the number of neighbors added in this call

    DETAILS
        Adds nearest neighbor cells of a square lattice to the
        current stack. The order is defined below beginning with cell 0.
        Cells which are not available are skipped.

        . . . . .
        . . 3 . .
        . 2 v 0 .
        . . 1 . .
        . . . . .
    '*/

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

int polyhexNeighbors( Node v, Stack<Node> &stack,
                      bool **avail, int const N_site )
{
    /*'
    Parameters
    ----------
    v:          Node, around which we find neighbor cells
    stack:      LIFO list, holds all prev added neighbors
    avail:      bool, TRUE when a cell can be added
    N_site:     int, defines size of grid variables and max depth
    
    Returns
    -------
    num_added:  the count of the number of neighbors added in this call

    DETAILS
        Adds nearest neighbor cells a honeycomb lattice to the
        current stack. The order is defined below beginning with cell 0.
        Cells which are not available are skipped.

        The lattice is mapped to a square lattice as follows...

         . . . . .              . . . . .
        . . 4 5 r .             . 4 5 r .
         . 3 v 0 .      -->     . 3 v 0 .
        . q 2 1 . .             . q 2 1 .
         . . . . .              . . . . .

        cell v: (i,j) does not neigbhor r: (i-1,j+1) or q: (i+1,j-1).
        
    '*/
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

int polyiamondNeighbors( Node v, Stack<Node> &stack,
                      bool **avail, int const N_site )
{
    /*'
    Parameters
    ----------
    v:          Node, around which we find neighbor cells
    stack:      LIFO list, holds all prev added neighbors
    avail:      bool, TRUE when a cell can be added
    N_site:     int, defines size of grid variables and max depth
    
    Returns
    -------
    num_added:  the count of the number of neighbors added in this call

    DETAILS
        Adds nearest neighbor cells a triangular lattice to the
        current stack. The order is defined below beginning with cell 0.
        Cells which are not available are skipped.


        The lattice can be represented as a rectangular lattice with each
        cell split into two triangles. There are two triangle types, marked
        "a" and "b" in the figure. Cell "B" has exactly three nearest
        neighbors, marked "A"
        .___.___.___.___.___.
        |\ a|\ a|\ a|\ a|\ a|   
        | \ | \ | \ | \ | \ |
        |b \|b \|b \|b \|b \|
        .___.___.___.___.___.
        |\ a|\ A|\ A|\ a|\ a|   
        | \ | \ | \ | \ | \ |
        |b \|b \|B \|b \|b \|
        .___.___.___.___.___.
        |\ a|\ a|\ A|\ a|\ a|   
        | \ | \ | \ | \ | \ |
        |b \|b \|b \|b \|b \|
        .___.___.___.___.___.
     
    '*/
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
  int polyshapeNeighbors(Node,Stack<Node> &,bool**,int const) )
{
    /*
    Parameters
    ----------
    stack:          LIFO list, holds explored cells
    avail:          FALSE, for used cells
    path:           Node array pointer, holds nodes in current graph
    depth:          int, monitors depth of recursion
    N_site:         int, defines size of grid related variables
    graph_count:    

    */
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
  int polyshapeNeighbors(Node,Stack<Node> &,bool**,int const) )
{
	/*'
    Parameters
    ----------
    N_site:                 int, defines grid size
    polyshapeNeighbors():   function, defines neighbor rules

    Returns
    -------
    graph_count:            int, total graphs with N_site cells

    DETAILS
             <---- 2*N_site-1 --->
        ^    X X ... X S 0 0 ... 0
        |    0 0 ... 0 0 0 0 ... 0 
    N_site   0 0 ... . . . . ... 0 
        |    . . ... . . . . ... . 
        v    0 0 ... . . . . ... 0

			X: not allowed
			0: available
			S: starting cell for all graphs 

	'*/
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
	start.i = 0;                        	//start S, @ (0,N_site-1)
	start.j = N_site-1;

	stack.Push(start);                      //initilize S to stack
	avail[0][N_site-1] = 0;                 //mark S as unavailable

	int graph_count = 0;
	int depth = 0;

	explore(stack,avail,path,depth,N_site,graph_count,polyshapeNeighbors);

	return graph_count;
}//generatePolyShape
