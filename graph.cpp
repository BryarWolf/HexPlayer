// graph construction

#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <ctime>

class Vertex; // forward reference needed for Edge class definition

class Edge{
  Vertex *next;
  float cost;
public:
  Edge(Vertex *nextV, float edgeCost) {
    next = nextV;
    cost = edgeCost;
  }
};

class Vertex{
  std::list<Edge> edges;
  int index;
public:
  Vertex(int vIndex){
    index = vIndex; 
  }
  void addEdge(Vertex nextV, float cost){
    edges.push_back(Edge(&nextV, cost));
  }
  int getIndex(){
    return index;
  }
};

class Graph{
  std::list<Vertex> vertices;
public:
  // function to initialize a graph with the specified number of vertices (numV),
  // graph density (density) and edge cost (range)
  // NOTE: the density value passed in and used was multiplied by 100 for use in
  // the edge creation tests
  void initGraph(int numV, float density, int range){
    int edgeCount = 0;
    float cost, avgEdgeCost = 0.0;
    std::list<Vertex>:: iterator j,k;

    // create the vertex list
    for (int i=0; i<numV; i++){
      vertices.push_back(Vertex(i));
    }
    std::cout << "This graph has " << numV << " vertices." << std::endl;

    // initialize random number generator
    srand(time(NULL));

    // iterate through the list of vertices to create edges
    // might be better to use while, but this works
    for (j=vertices.begin(); j != vertices.end(); j++){
      // iterate through the list again to test for edges between j and k
      for (k=j; k != vertices.end(); k++) {
	if (j == k) continue;  // Ignore circular edges
	else {
	  // test a random number to see if it is less than or equal to density
	  if ((rand() % 100) <= density) {
	    // if test passed, add edge between vertex i and j with a random cost
	    // between 1 and 10
	    cost = rand() % range + 1;
	    // std::cout << "New edge from " << j->getIndex() << " to ";
	    // std::cout << k->getIndex() << " with a cost of " << cost << std::endl;
	    avgEdgeCost += cost;
	    j->addEdge(*k, cost);
	    edgeCount++;
	  }
	}
      }
    }
    avgEdgeCost /= edgeCount;
    std::cout << "With Graph Density=" << density << "%, " << edgeCount;
    std::cout << " edges were created." << std::endl;
    std::cout << "The average edge cost is " << avgEdgeCost << "." << std::endl;
  }
  int numVertices() {
    return vertices.size();
  }
};

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: Number of nodes, Graph Density, Maximum Distance" << std::endl;
    return 1;
  }
  int numVertices = atoi(argv[1]); // Holds user entry for number of nodes
  float graphDensity = atof(argv[2]); // Holds user entry for graph density
  int maxRange = atoi(argv[3]); // Holds user entry for maximum range of edges
  std::cout << "User Entries: Graph size=" << numVertices;
  std::cout << ", Graph density=" << graphDensity;
  std::cout << ", Range=1-" << maxRange << std::endl << std::endl;

  // Define and initialize a graph using the user inputs
  Graph tGraph;
  tGraph.initGraph(numVertices, graphDensity*100, maxRange);
}

