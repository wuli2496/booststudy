#pragma once
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/undirected_graph.hpp>

//https://www.ibm.com/developerworks/cn/aix/library/au-aix-boost-graph/

using namespace boost;

void graph_add_edge()
{
	typedef boost::adjacency_list<listS, vecS, undirectedS> mygraph;

	mygraph g;
	add_edge(0, 1, g);
	add_edge(0, 3, g);
	add_edge(1, 2, g);
	add_edge(2, 3, g);

}

void graph_traverse()
{
	typedef boost::adjacency_list<listS, vecS, undirectedS> mygraph;

	mygraph g;
	add_edge(0, 1, g);
	add_edge(0, 3, g);
	add_edge(1, 2, g);
	add_edge(2, 3, g);
	mygraph::vertex_iterator vertexIt, vertexEnd;
	mygraph::adjacency_iterator neighbourIt, neighbourEnd;
	tie(vertexIt, vertexEnd) = vertices(g);
	for (; vertexIt != vertexEnd; vertexIt++)
	{
		cout << *vertexIt << " is connected with ";
		tie(neighbourIt, neighbourEnd) = adjacent_vertices(*vertexIt, g);
		for (; neighbourIt != neighbourEnd; neighbourIt++)
		{
			cout << *neighbourIt << " ";
		}
		cout << "\n";
	}
}

void graph_create_directedGraph()
{
	typedef boost::adjacency_list<listS, vecS, directedS> mygraph;
	mygraph g;
	add_edge(0, 1, g);
	add_edge(0, 3, g);
	add_edge(1, 2, g);
	add_edge(2, 3, g);
}

void graph_create_undirectedGraph()
{
	undirected_graph<> g;
	undirected_graph<>::vertex_descriptor u = g.add_vertex();
	undirected_graph<>::vertex_descriptor v = g.add_vertex();
	undirected_graph<>::vertex_descriptor w = g.add_vertex();
	undirected_graph<>::vertex_descriptor x = g.add_vertex();
	add_edge(u, v, g);
	add_edge(u, w, g);
	add_edge(u, x, g);
	cout << "Degree of u: " << degree(u, g) << endl;
}

void graph_in_out_degree()
{
	typedef boost::adjacency_list<listS, vecS, directedS> mygraph;

	mygraph g;
	add_edge(0, 1, g);
	add_edge(0, 3, g);
	add_edge(1, 2, g);
	add_edge(2, 3, g);
	mygraph::vertex_iterator vertexIt, vertexEnd;
	mygraph::in_edge_iterator inedgeIt, inedgeEnd;
	mygraph::in_edge_iterator outedgeIt, outedgeEnd;
	tie(vertexIt, vertexEnd) = vertices(g);
	for (; vertexIt != vertexEnd; vertexIt++)
	{
		cout << "incoming edges for " << *vertexIt << ": ";
		//tie(inedgeIt, inedgeEnd) = in_edges(*vertexIt, g);
	}
}