#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver()
{
    nodesExplored = new NodeList();
}

PathSolver::~PathSolver()
{
    delete nodesExplored;
}

void PathSolver::forwardSearch(Env env)
{

    // Input: S- start location of the robot in the environment
    Node *p = get(env, 'S');
    // Input: G- goal location for the robot to get reach
    Node *goal = get(env, 'G');

    // Let P be a list of positions the robot can reach, with distances (initially contains S). This is also called the open-list.
    NodeList *openList = new NodeList();
    openList->addElement(p);

    // do until the robot reaches the goal, that is, p == G, or no such position p can be found
    while (env[p->getCol()][p->getRow()] != 'G' &&
           !openList->isSupersetOf(nodesExplored))
    {
        //sets p to the node closest to the end of openList that is not in closedList. Used mainly to get rid of the old p node, and replace it with a valid node (but not optimal.. yet)
        for (int i = 0; i < openList->getLength() && nodesExplored->doesContain(p); i++)
        {
            p = openList->getNode(i);
        }

        //sets p to the node in openList that has the smallest estimated distance  to the goal, and is not in closedList.
        for (int i = 0; i < openList->getLength(); i++)
        {
            Node *candidateNode = openList->getNode(i);

            if ((p->getEstimatedDist2Goal(goal) >= candidateNode->getEstimatedDist2Goal(goal)) &&
                !nodesExplored->doesContain(candidateNode))
            {
                p = candidateNode;
            }
        }

        // for Each position q in Env that the robot can reach from p do

        // Set the distance_travelled of q to be one more that that of p
        NodeList *nearbyNodes = getNearbyNodes(p);

        // Add q to open-list P only if it is not already in it.
        for (int i = 0; i < nearbyNodes->getLength(); i++)
        {
            Node *candidate = nearbyNodes->getNode(i);

            if (!openList->doesContain(candidate) && (env[candidate->getCol()][candidate->getRow()] == '.' || env[candidate->getCol()][candidate->getRow()] == 'G'))
            {
                openList->addElement(new Node(*candidate));
            }
        }
        delete nearbyNodes;
        // end for

        // Add p to closed-list C.
        nodesExplored->addElement(new Node(*p));
    }

    delete openList;
    delete goal;
}

Node *PathSolver::get(Env env, char charToFind)
{
    Node *node = nullptr;
    for (int i = 0; i < ENV_DIM; i++)
    {
        for (int j = 0; j < ENV_DIM; j++)
        {
            if (env[j][i] == charToFind)
            {
                node = new Node(i, j, 0);
            }
        }
    }
    return node;
}

NodeList *PathSolver::getNodesExplored()
{ // Deep copy of nodesExplored
    return new NodeList(*nodesExplored);
}

NodeList *PathSolver::getPath(Env env)
{
    Node *start = nodesExplored->getNode(0);
    Node *goal = nodesExplored->getNode(nodesExplored->getLength() - 1);

    NodeList *backwardPath = new NodeList;

    // Hint: “Start from the goal node in the list nodesExplored.  This would be your final element of the path.
    backwardPath->addElement(new Node(*goal));

    // Repeat this backtracking process for each node you add to the path until you reach the start node.”
    while (!backwardPath->doesContain(start))
    {
        Node *currentNode = backwardPath->getNode(backwardPath->getLength() - 1);
        // Search for the the four neighbours of the goal node in nodesExplored.
        NodeList *nearbyNodes = getNearbyNodes(nodesExplored, currentNode);

        for (int i = 0; i < nearbyNodes->getLength(); i++)
        {
            Node *candidate = nearbyNodes->getNode(i);

            // If there is a neighbour that has distance_traveled one less than the current node. Then that should be the node in the path before the current node.
            if (!backwardPath->doesContain(candidate) && candidate->getDistanceTraveled() < currentNode->getDistanceTraveled())
            {
                backwardPath->addElement(new Node(*candidate));
            }
        }
        delete nearbyNodes;
    }

    // Think carefully the path that you return must be from start to finish, not finish to start.

    // reverse list
    NodeList *forwardPath = new NodeList();
    for (int i = backwardPath->getLength(); i > 0; i--)
    {
        Node *node = backwardPath->getNode(i - 1);
        forwardPath->addElement(new Node(*node));
    }
    
    delete backwardPath;

    return forwardPath;
}

//-----------------------------

NodeList *PathSolver::getNearbyNodes(Node *node)
{
    int row = node->getRow();
    int col = node->getCol();
    int dist = node->getDistanceTraveled();
    NodeList *nearbyNodes = new NodeList();

    //up
    nearbyNodes->addElement(new Node(row - 1, col, dist + 1));

    //right
    nearbyNodes->addElement(new Node(row, col + 1, dist + 1));

    //down
    nearbyNodes->addElement(new Node(row + 1, col, dist + 1));

    //left
    nearbyNodes->addElement(new Node(row, col - 1, dist + 1));

    return nearbyNodes;
}

NodeList *PathSolver::getNearbyNodes(NodeList *nodeList, Node *node)
{
    NodeList *nearbyNodes = new NodeList();
    for (int i = 0; i < nodeList->getLength(); i++)
    {
        Node *candidate = nodesExplored->getNode(i);

        //if there is a difference of 1 in row and 0 in col, or vice versa, then the candidate node must be adjacent, and is added to nearbyNodes

        if ((((abs(candidate->getCol() - node->getCol()) == 1 &&
               abs(candidate->getRow() - node->getRow()) == 0)) ||

             ((abs(candidate->getRow() - node->getRow()) == 1 &&
               abs(candidate->getCol() - node->getCol()) == 0))))
        {
            nearbyNodes->addElement(new Node(*candidate));
        }
    }
    
    return nearbyNodes;
}