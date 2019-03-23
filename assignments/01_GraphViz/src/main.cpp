#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
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

const double kPi = 3.14159265358979323;

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
//        if (!getline(cin, graphName)) {
//            cout << endl << "Cant get what you typed, please try again" << endl;
//            continue;
//        }
        graphName = "./res/10grid";
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
    double theta = 2.0*kPi*((double) index)/((double) nodesNum);
    double preTheta = 2.0*kPi*((double) index - 1)/((double) nodesNum);
    node.x = cos(theta);
    node.y = sin(theta);
    double preX = cos(preTheta);
    double preY = sin(preTheta);
    double delta = std::sqrt(std::pow(node.x - preX, 2) + std::pow(node.y - preY, 2));
    cout << "index: " << index << endl;
    cout << std::setw(6) << "theta: " << theta << " preTheta: " << preTheta << " preX: " << preX << " preY: " << preY
         << " X - preX: " << node.x - preX << " Y - preY: " << node.y - preY << " delta: " << delta << endl;


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

    // Setup nodes
    for (int i=0; i < nodesNum; ++i) {
        initNodePosInCircle(i, nodesNum, graph.nodes[i]);
    }

    // Setup edges
    while (getline(graphFile, oneLine)) {
        Edge edge;
        clearConverter(converter);
        converter << oneLine;
        converter >> edge.start >> edge.end;  // end=8 start=578550992 why?!

        graph.edges.push_back(edge);
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
