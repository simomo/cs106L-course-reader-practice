#include <iostream>
#include <string>
#include <fstream>
#include "SimpleGraph.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

void Welcome();
void UserInputName(string& graphName, ifstream& graphFile);
void LoadGraphFile(string graphName, SimpleGraph& graph);

// Main method
int main() {
    Welcome();
    SimpleGraph graph;
    string graphName;
    ifstream graphFile;

    UserInputName(graphName, graphFile);
    LoadGraphFile("10clique", graph);
    InitGraphVisualizer(graph);
    DrawGraph(graph);
    //TODO: Iteration & time elapse
    return 0;
}

void UserInputName(string& graphName, ifstream& graphFile) {
    while (true) {
        cout << "Please enter the graph file name: ";
        if (!getline(cin, graphName)) {
            cout << endl << "Cant get what you typed, please try again" << endl;
            continue;
        }

        graphFile.open(graphName);
        if (graphFile.is_open()) {
            break;
        }

        cout << endl << "Cant open the file " << graphName << endl;
    }


}

void LoadGraphFile(string graphName, SimpleGraph& graph) {}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}
