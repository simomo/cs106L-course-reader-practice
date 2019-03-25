#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <thread>
#include <vector>
#include "SimpleGraph.h"

#define PIX_MAX 200

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::vector;

void Welcome();
void UserInputName(string& graphName, ifstream& graphFile);
void LoadGraphFile(ifstream& graphFile, SimpleGraph& graph);
void oneIter(SimpleGraph& graph);
void calculateNodesForce(vector<Node>::iterator& i, vector<Node>::iterator& j);
void calculateEdgesForce(vector<Edge>::iterator& k, vector<Node>& allNodes);
void updateAllNodes(vector<Node>& allNodes);

const double kPi = 3.14159265358979323;
const double kRepel = 0.001;
const double kAttract = 0.001;

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
    for (int i=0; i < 100; ++i) {
        oneIter(graph);
        DrawGraph(graph);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
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
    double theta = 2.0*kPi*index/nodesNum;
    node.x = cos(theta);
    node.y = sin(theta);
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

void oneIter(SimpleGraph& graph) {
    for (std::vector<Node>::iterator i = graph.nodes.begin(); i != graph.nodes.end(); ++i) {
        for (std::vector<Node>::iterator j = graph.nodes.begin(); j != graph.nodes.end(); ++j) {
            if (j == i) {
                continue;
            }
            calculateNodesForce(i, j);
        }
    }

    for (std::vector<Edge>::iterator k = graph.edges.begin(); k != graph.edges.end(); ++k) {
        calculateEdgesForce(k, graph.nodes);
    }

    updateAllNodes(graph.nodes);
}

void calculateNodesForce(vector<Node>::iterator& i, vector<Node>::iterator& j) {
    double f = kRepel / sqrt(pow((j->y - i->y), 2) + pow((j->x - i->x), 2));
    double theta = atan2((j->y - i->y), (j->x - i->x));
    i->deltaX -= f * cos(theta);
    i->deltaY -= f * sin(theta);
    j->deltaX += f * cos(theta);
    j->deltaY += f * sin(theta);
}

void calculateEdgesForce(vector<Edge>::iterator& k, vector<Node>& allNodes) {
    Node *i = &allNodes[k->start];
    Node *j = &allNodes[k->end];
    double f = kAttract * (pow((j->y - i->y), 2) + pow((j->x - i->x), 2));
    double theta = atan2((j->y - i->y), (j->x - i->x));
    i->deltaX += f * cos(theta);
    i->deltaY += f * sin(theta);
    j->deltaX -= f * cos(theta);
    j->deltaY -= f * sin(theta);
}
void updateAllNodes(vector<Node>& allNodes) {}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}
