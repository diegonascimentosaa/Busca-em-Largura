#include <iostream>
#include <list>

using namespace std;

class Grafo
{
	int V;

	list<int> *adj;

	void BFSUtil(int v, bool visited[]);
public:
	Grafo(int V);

	void addEdge(int v, int w);

	void BFS(int v);
};

Grafo::Grafo(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Grafo::BFSUtil(int v, bool visited[])
{
	list<int> queue;

	visited[v] = true;
	queue.push_back(v);

	list<int>::iterator i;

	while (!queue.empty())
	{
		v = queue.front();
		cout << v << " ";
		queue.pop_front();

		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

void Grafo::BFS(int v)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	BFSUtil(v, visited);
}

int main()
{

	Grafo g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Seguindo a busca em largura a partir do vértice 2:\n";
	g.BFS(2);

	return 0;
}
