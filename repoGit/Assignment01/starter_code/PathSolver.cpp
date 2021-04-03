#include "PathSolver.h"
#include <iostream>

//TODO DELETE USINGS
using std::cout;
using std::endl;

PathSolver::PathSolver()
{
    // TODO
    // nodesExplored->addElement(START_ELEMENT)
    nodesExplored = new NodeList();
    nodesExplored->addElement(new Node(1, 2, 3));
    cout << "Row of 1st node in pathSolver: ";
    cout << nodesExplored->getNode(0)->getRow() << endl;
    cout << "address of 1st node in pathSolver: ";
    cout << nodesExplored->getNode(0) << endl;
    cout << "address of NodeListin pathSolver: ";
    cout << nodesExplored << endl;
}

PathSolver::~PathSolver()
{
    // TODO
}

void PathSolver::forwardSearch(Env env)
{
    // TODO
}

NodeList *PathSolver::getNodesExplored()
{ //Deep copy of nodesExplored
    NodeList *nodeList = new NodeList();
    for (int i = 0; nodesExplored != nullptr && i < nodesExplored->getLength(); i++)
    {
        Node node = *nodesExplored->getNode(i);
        nodeList->addElement(new Node(node.getRow(), node.getCol(), node.getDistanceTraveled()));
    }
    return nodeList;
}

NodeList *PathSolver::getPath(Env env)
{
    // TODO
    return nullptr;
}

//-----------------------------