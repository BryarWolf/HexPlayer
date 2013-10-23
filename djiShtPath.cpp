
// Djikstra's Shortest Path algorirtm implementation

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 3) {
    cerr << "Usage: Number of nodes, Graph Density, Maximum Distance" << endl;
    return 1;
  }
  int numNodes = atoi(argv[1]); // Holds user entry for number of nodes
  float graphDensity = atoi(argv[2]); // Holds user entry for graph density
  float maxRange = atof(argv[3]); // Holds user entry for maximum range of edges
  cout << "Number of nodes: " << numNodes << endl;
  cout << "Graph density: " << graphDensity << endl;
  cout << "Distance range: 1.0-" << maxRange << endl;
  cout << "Average path length: TBD" << endl;
}
