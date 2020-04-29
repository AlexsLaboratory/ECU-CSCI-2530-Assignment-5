// CSCI 2530
// Assignment: 5
// Author:     Alex Lowe
// File:       mst.cpp
// Tab stops:  None

// This program takes in a weighted graph by taking in the number the
// vertices, vertex 1, vertex 2, and the weight of the graph. The program
// then sorts the edges by ascending weight. It then uses Kruskal's algorithm
// and finds the minimal weight spanning tree. For each edge it prints out
// vertex 1, vertex 2 and the weight of that edge.

// The program outputs the original graph with the vertices and weight along
// with the number of vertices and edges. The program then prints the minimal
// spanning tree with the number of vertices and edges along with the
// vertices and weight. Finally it prints the total weight of the spanning tree.

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "equiv.h"

using namespace std;

// An object of type Edge represents the node one and node two along with the
// weight of each line or edge.

struct Edge
{
    int v1;
    int v2;
    int weight;

    Edge() {
      v1 = 0;
      v2 = 0;
      weight = 0;
    }
};

// An object of type Graph represents the number of vertices, number of
// edges, and size of graph. edges is a structure that holds vertex one and
// two along with the weight of each edge

struct Graph
{
    int numVert;
    int numEdge;
    Edge *edges;
    int size;

    Graph(int n, int e) {
      numVert = n;
      numEdge = 0;
      size = e;
      edges = new Edge[e];
    }
};

// InsertEdge inserts an edge between vertices u and v, of weight w, into
// graph g.

void insertEdge(int u, int v, int w, Graph *g)
{
  g->edges[g->numEdge].weight = w;
  g->edges[g->numEdge].v1 = u;
  g->edges[g->numEdge].v2 = v;
  g->numEdge++;
}

// ReadGraph allocates a graph in the heap with enough room for e edges. It
// reads a graph from the standard input in the input format and returns a
// pointer to that graph.

Graph *readGraph(int e)
{
  int numVert;
  int v1;
  int v2;
  int weight;
  scanf("%i", &numVert);
  Graph *g = new Graph(numVert, e);
  while (scanf("%i", &v1) == 1 && v1 != 0)
  {
    scanf("%i", &v2);
    scanf("%i", &weight);
    insertEdge(v1, v2, weight, g);
  }
  return g;
}

// WriteGraph writes graph g in the output format. WriteGraph shows the
// number of vertices and the number of edges, but otherwise does not write a
// heading. It is the caller's responsibility to label the graph.

void writeGraph(const Graph *g)
{
  printf("There are %i and %i edges\n", g->numVert, g->numEdge);
  printf("vertices           weight\n");
  for (int i = 0; i < g->numEdge; ++i)
  {
    printf("%i     %i            %i\n",g->edges[i].v1, g->edges[i].v2,
           g->edges[i].weight);
  }
}

// compareEdges compares the edges.

int compareEdges(const Edge* A, const Edge* B)
{
  return A->weight - B->weight;
}
typedef int (*QSORT_COMPARE_TYPE)(const void*, const void*);

// SortEdges sorts the edges of g into non-decreasing order by weight.

void sortEdges(Graph *g)
{
  qsort(g->edges, g->numEdge, sizeof(Edge), (QSORT_COMPARE_TYPE) compareEdges);
}

// MinimalSpanningTree returns a minimal spanning tree of g. It must not
// change g.

Graph *minimalSpanningTree(Graph *g)
{
  Graph *spanning = new Graph(g->numVert, g->size);
  sortEdges(g);
  ER equiv = newER(g->numVert);
  for (int i = 0; i < g->numEdge; ++i)
  {
    if (!equivalent(equiv, g->edges[i].v1, g->edges[i].v2))
    {
      combine(equiv, g->edges[i].v1, g->edges[i].v2);
      insertEdge(g->edges[i].v1, g->edges[i].v2, g->edges[i].weight, spanning);
    }
  }
  return spanning;
}

// TotalWeight returns the sum of the weights of the edges in g.

int totalWeight(const Graph *g)
{
  int totWeight = 0;
  for (int i = 0; i < g->numEdge; ++i)
  {
    totWeight += g->edges[i].weight;
  }
  return totWeight;
}


int main()
{
  Graph *test = readGraph(100);
  sortEdges(test);
  writeGraph(test);

  Graph *spanning = minimalSpanningTree(test);
  writeGraph(spanning);
  printf("The total weight of the spanning tree is %i.\n", totalWeight
  (spanning));
}