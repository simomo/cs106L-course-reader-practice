#include <iostream>
#include <string>
#include "SimpleGraph.h"

using std::cout;	using std::endl;
using std::string;

void Welcome();
void UserInputName(string& graphName);
void LoadGraphFile(string graphName, SimpleGraph& graph);

// Main method
int main() {
    Welcome();
    SimpleGraph graph;
    string graphName;

    UserInputName(graphName);
    LoadGraphFile("10clique", graph);
    InitGraphVisualizer(graph);
    DrawGraph(graph);
    //TODO: Iteration & time elapse
    return 0;
}

void UserInputName(string& graphName) {}

void LoadGraphFile(string graphName, SimpleGraph& graph) {}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}
