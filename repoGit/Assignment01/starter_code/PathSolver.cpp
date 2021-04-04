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
}

PathSolver::~PathSolver()
{
    // TODO
    delete nodesExplored;
}

void PathSolver::forwardSearch(Env env)
{

    // TODO
    // Input: E- the environment
    // Input: S- start location of the robot in the environment
    Node *start = get(env, 'S');
    // Input: G- goal location for the robot to get reach
    Node *goal = get(env, 'G'); //TODO may need to change dist_travelled in this node
    // Let P be a list of positions the robot can reach, with distances (initially contains S). This is also called the open-list.
    //*getAll(env, '.')

    NodeList *openList = new NodeList();
    openList->addElement(start);

    //LOOP:
    Node *closestNode = nullptr;
    for (int i = 0; i < openList->getLength(); i++)
    {
        if (closestNode == nullptr)
        {
            closestNode = openList->getNode(i);
        }
        if (closestNode->getEstimatedDist2Goal(goal) > openList->getNode(i)->getEstimatedDist2Goal(goal)){
            closestNode = openList->getNode(i);
        }
    }

    cout << closestNode->toString() << endl;
    // cout << start->getEstimatedDist2Goal(goal) << endl;

    // cout << openList->getLength() << endl;

    // Let C be a list of positions the that has already being explored, with distances (initially empty). This is also called the closed-list.
    //this list is pathsExplored.

    // repeat:
    // Select the node p from the open-list P that has the smallest estimated distance (see Section 3.2.2) to goal and, is not in the closed-list C.
    // for Each position q in Env that the robot can reach from p do
    // Set the distance_travelled of q to be one more that that of p
    // Add q to open-list P only if it is not already in it.
    // end
    // Add p to closed-list C.
    // until The robot reaches the goal, that is, p == G, or no such position p can be found
}

Node *PathSolver::get(Env env, char charToFind)
{
    Node *node = nullptr;
    for (int i = 1; i < ENV_DIM; i++)
    {
        for (int j = 1; j < ENV_DIM; j++)
        {
            if (env[i][j] == charToFind)
            {
                node = new Node(i, j, 0);
            }
        }
    }
    return node;
}

// NodeList *getAll(Env env, char charToFind)
// {
//     NodeList *nodeList = nullptr;
//     for (int i = 1; i < ENV_DIM; i++)
//     {
//         for (int j = 1; j < ENV_DIM; j++)
//         {
//             if (env[i][j] == charToFind)
//             {
//                 nodeList->addElement(new Node(i, j, 0));
//             }
//         }
//     }
//     return nodeList;
// }

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