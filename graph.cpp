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
    cost = edgeCost
};

class Vertex{
  std::list<Edge> *edges;
  int index;
public:
  Vertex(int vIndex){
    index = vIndex; 
  }
  void addEdge(Vertex *nextV, float cost){
    edges.push_back(Edge(nextV, cost));
  }
};

class Graph{
  std::list<Vertex> vertices;
public:
  void initGraph(int numV, float density, float range) {
    // create the vertex list
    for (int i=0; i<numV; i++){
      vertices.push_back(Vertex(i));
    }

    // initialize random number generator
    srand(time(NULL));

    // iterate through the list of vertices to create edges 
    for (std::list<Vertex>::iterator j=vertices.begin(); j != vertices.end(); j++){
      // iterate through the list again to test for edges betwenn j and k
      for (std:list<Vertex>::iterator k=vertices.begin(); k != vertices.end(); k++) {
	  if (j == k) break;  // Ignore circular edges
	  else {
	    // test a random number to see if it is less than or equal to density
	    if ((rand % 100) <= density) {
	      // if test passed, add edge between vertex i and j with a random cost
	      // between 1 and 10
	      j.addEdge(&k, (rand() % 10 + 1));
	    }
	  }
	}
      }
    }
  }
};

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: Number of nodes, Graph Density, Maximum Distance" << std::endl;
    return 1;
  }
  int numVertices = atoi(argv[1]); // Holds user entry for number of nodes
  float graphDensity = atof(argv[2]); // Holds user entry for graph density
  float maxRange = atof(argv[3]); // Holds user entry for maximum range of edges
  std::cout << "User Entry for graph size: " << numVertices << std::endl;
  std::cout << "Graph density: " << graphDensity << std::endl;
  std::cout << "Distance range: 1-" << maxRange << std::endl;
  std::cout << "Average path length: TBD" << std::endl;

  // Define and initialize a graph using the user inputs
  Graph tGraph;
  tGraph.initGraph(numVertices, graphDensity*100, maxRange);
  std::cout << "Graph has " << tGraph.numVertices() << " vertices" << std::endl;
}

