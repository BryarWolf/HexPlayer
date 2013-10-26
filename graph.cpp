// graph construction

#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>

class Vertex; // forward reference needed for Edge class definition

class Edge{
  Vertex *next;
  Edge *nextEdge;
  Edge *prevEdge;
  int cost;
};

class Vertex{
  std::list<Edge> *edges;
  std::string name;
  Vertex *next;
  Vertex *prev;
};

class Graph{
  std::list<Vertex> *vertices;
public:
  void initGraph(int numVertices) {
    std::string temp = NULL;
    int i=0;
    Vertex *vertices = new Vertex;
    vertices->name = std::to_string(i);
    for (int i=1; i<numVertices; i++){
      temp = std::to_string(i);
      vertices.addVertex(temp);
    }
  };
  void addVertex(std::string vName) {
    Vertex* newV = new Vertex;
    name = vName;
    vertices.push_back(newV);
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
  tGraph.initGraph(numVertices);
  std::cout << "Graph has " << tGraph.numVertices() << " vertices" << std::endl;
}

