// AdvProg-Assg.2-Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

int nr_friends = 0;

struct Vertex {
	std::vector<Vertex*> edges;
	bool visited = false;
	int position = 0;

	Vertex(int pos) : position(pos) {}
};

class Graph {
public:
	std::vector<Vertex*> vertices;

	int nr_vertices = 0,
		nr_edges = 0;

	Graph(int i, int j) : nr_vertices(i), nr_edges(j) {
		for (int i = 0; i < nr_vertices; i++)
		{
			Vertex* temp = new Vertex(i + 1);
			vertices.push_back(temp);
		}
	}

	Vertex* findVertex(int pos) {
		if (pos == vertices[pos - 1]->position)
			return vertices[pos - 1];

		return nullptr;
	}

	void addEdge(int lhs, int rhs) {
		Vertex* v = findVertex(lhs);
		Vertex* w = findVertex(rhs);
		v->edges.push_back(w);
		w->edges.push_back(v);
	}

};

void Explore(Vertex* vect, int& counter) {
	vect->visited = true;
	++counter;
	for (int i = 0; i < vect->edges.size(); i++)
	{
		if (!vect->edges[i]->visited) {
			Explore(vect->edges[i], counter);
		}
	}

}

void DFS(Graph &graph) {
	int connected = 0;

	for (int i = 0; i < graph.nr_vertices; i++)
	{
		int index = 0;
		if (!graph.vertices[i]->visited) {
			Explore(graph.vertices[i], index);
			++connected;
		}
		if (index > nr_friends)
			nr_friends = index;
	}
	//if connected > 1 then graph isnt connected
}

int main()
{
	int testcases = 0;
	std::cin >> testcases;
	Graph *graph = nullptr;

	while (testcases--) {
		int i, j;
		std::cin >> i >> j;
		graph = new Graph(i, j);
		nr_friends = 0;

		while (j--) {
			int lhs, rhs;
			std::cin >> lhs >> rhs;
			graph->addEdge(lhs, rhs);
		}

		DFS(*graph);
		std::cout << nr_friends << std::endl;
	}


	return 0;
}

