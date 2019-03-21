#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include "SimpleGraph.h"

#define PIX_MAX 200

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

void Welcome();
void UserInputName(string& graphName, ifstream& graphFile);
void LoadGraphFile(ifstream& graphFile, SimpleGraph& graph);

const double kPi = 3.1415926535;

// Main method
int main() {
    Welcome();
    SimpleGraph graph;
    string graphName;
    ifstream graphFile;

    UserInputName(graphName, graphFile);
    LoadGraphFile(graphFile, graph);
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

void inline randNodePos(Node& node) {
    node.x = rand() % PIX_MAX;
    node.y = rand() % PIX_MAX;
}

void inline initNodePosInCircle(int index, int nodesNum, Node& node) {
    node.x = cos(2*kPi*index/nodesNum);
    node.y = sin(2*kPi*index/nodesNum);
}

void clearConverter(stringstream& converter) {
    converter.str("");
    converter.clear();
}

void LoadGraphFile(ifstream& graphFile, SimpleGraph& graph) {
    stringstream converter;
    string nodesNumStr;
    int nodesNum;

    string oneLine;

    if (!getline(graphFile, nodesNumStr)) {return;}

    converter << nodesNumStr;
    converter >> nodesNum;
    graph.nodes.resize(nodesNum);

    int i = 0;
    while (getline(graphFile, oneLine)) {
        Edge edge;
        clearConverter(converter);
        converter << oneLine;
        converter >> edge.start >> edge.end;  // end=8 start=578550992 why?!

        graph.edges.push_back(edge);

        initNodePosInCircle(i, nodesNum, graph.nodes[edge.start]);
        initNodePosInCircle(i, nodesNum, graph.nodes[edge.end]);
//        randNodePos(graph.nodes[edge.start]);
//        randNodePos(graph.nodes[edge.end]);
        ++i;
    }
}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}
