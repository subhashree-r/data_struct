// An Iterative C++ program to do DFS traversal from
// a given source vertex. DFS(int s) traverses vertices
// reachable from s.
#include<bits/stdc++.h>
using namespace std;

// This class represents a directed graph using adjacency
// list representation
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // adjacency lists
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	void DFS(int s); // prints all vertices in DFS manner
	// from a given source.
};

Graph::Graph(int V)
{
    this->V=V;
    adj= new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// prints all not yet visited vertices reachable from s
void Graph::DFS(int s)
{
    //creating a visited vector of size of vertices
    std::vector<bool> visited(V,false);
    std::stack<int> stack;
    stack.push(s);
    while(!stack.empty())
    {

        s=stack.top();
        stack.pop();
        if(!visited[s])
        {
            cout<<" "<<s;
            visited[s]=true;
        }
        //push the adjacent vertices for DFS
        for(auto i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                stack.push(*i);
            }
        }
    }
}

// Driver program to test methods of graph class
int main()
{
	Graph g(5); // Total 5 vertices in graph
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 4);

	cout << "Following is Depth First Traversal\n";
	g.DFS(0);

	return 0;
}
