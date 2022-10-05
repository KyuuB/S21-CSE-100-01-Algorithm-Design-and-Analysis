
//Source code help from geeksforgeeks.org/strongly-connected-components/

#include <stack>
#include <list>
#include <iostream>

using namespace std;

class Graph
{
	int V; 
	list<int> *adj; 
	
	void DFS(int v, bool visited[], int verticeArray[], int count);

	void fillStack(int v, bool visited[], stack<int> &Stack);
	
public:
	Graph(int V);
	
	void print();

	Graph transpose();

	void addEdge(int v, int w);
};

Graph::Graph(int V)
{
	this->V = V;

	adj = new list<int>[V];

}


void Graph::DFS(int v, bool visited[], int verticeArray[], int count)
{
	//cout << v;
	visited[v] = true;
	verticeArray[v] = count;
	
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i){

		if (!visited[*i]){

			DFS(*i, visited, verticeArray, count);
		}
	}
	
}

Graph Graph::transpose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::fillStack(int v, bool visited[], stack<int> &Stack)
{
	
	visited[v] = true;

	
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			fillStack(*i, visited, Stack);

	
	Stack.push(v);
}


void Graph::print()
{
	stack<int> Stack;
	int verticeArray[V];
	int count = 0;
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	
	for(int i = 0; i < V; i++)
		if(visited[i] == false)
			fillStack(i, visited, Stack);

	
	Graph gr = transpose();


	for(int i = 0; i < V; i++)
		visited[i] = false;


	while (Stack.empty() == false)
	{
		int v = Stack.top();
		Stack.pop();

		if (visited[v] == false)
		{
			gr.DFS(v, visited, verticeArray, count);
			//cout << endl;
			count++;
		}
	}

	int newArray[V];

	for (int i = 0; i < V; i++)
	{
		newArray[i] = verticeArray[i];
	}
	
	for (int i = 0; i < V; i++)
	{
		bool change = false;
		for(int j = i + 1; j < V; j++) {
			if(verticeArray[i] == verticeArray[j]){
				newArray[j] = i;
				change = true;
			}

		}
		if(change == false){
			newArray[i] = i;
		}
	}
	
	
	
	for (int i = 0; i < V; i++)
	{
		cout << newArray[i] << endl;
	}
	
	
}

int main()
{
    int numVertices, numEdges;
    int temp1, temp2;
    cin >> numVertices;
    cin >> numEdges;
	

	Graph g(numVertices);
	
    for (int i = 0; i < numEdges; i++)
    {
        cin >> temp1;
        cin >> temp2;
        g.addEdge(temp1, temp2);
    }

	g.print();

	return 0;
}
