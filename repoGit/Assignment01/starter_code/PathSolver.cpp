#include "PathSolver.h"
#include <iostream>

//TODO DELETE USINGS
using std::cout;
using std::endl;

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

    //LOOP:
    while (env[p->getCol()][p->getRow()] != 'G' &&
           !openList->equals(nodesExplored))
    {
        // repeat:
        // Select the node p from the open-list P that has the smallest estimated distance (see Section 3.2.2) to goal and, is not in the closed-list C.

        //sets p to the node closest to the end of openList that is not in closedList. Used mainly to get rid of the old p.
        for (int j = 0; j < openList->getLength() && nodesExplored->doesContain(p); j++)
        {
            p = openList->getNode(j);
        }

        //sets p to the node in openList which is closest to the goal, and not in closedList.
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
        // Add q to open-list P only if it is not already in it.

        NodeList *nearbyNodes = getNearbyNodes(p);

        for (int i = 0; i < nearbyNodes->getLength(); i++)
        {
            Node *candidate = nearbyNodes->getNode(i);

            if (!openList->doesContain(candidate) && (env[candidate->getCol()][candidate->getRow()] == '.' || env[candidate->getCol()][candidate->getRow()] == 'G'))
            {
                // openList->addElement(new Node(*candidate));
                // cout << "candidate: " <<candidate->toString()<< ". mem: " << &candidate << endl;
                // Node * copy = new Node(*candidate);
                // cout << "cand copy: " <<copy->toString()<< ". mem: " << &copy << endl;
                // openList->addElement(new Node(*candidate));

                openList->addElement(new Node(*candidate));
            }
        }
        delete nearbyNodes;
        // end

        // Add p to closed-list C.

        nodesExplored->addElement(new Node(*p));
    }

    // until The robot reaches the goal, that is, p == G, or no such position p can be found

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
    // Then search for the the four neighbours of the goal node in nodesExplored. If there is a neighbour that has distance_traveled one less than the goal node. Then that should be the node in the path before the goal node.

    while (!backwardPath->doesContain(start))
    {
        Node *currentNode = backwardPath->getNode(backwardPath->getLength()-1);

        NodeList *nearbyNodes = getNearbyNodes(nodesExplored, currentNode);
        for (int i = 0; i < nearbyNodes->getLength(); i++)
        {
            Node *candidate = nearbyNodes->getNode(i);

            if (!backwardPath->doesContain(candidate) && candidate->getDistanceTraveled() < currentNode->getDistanceTraveled())
            {
                backwardPath->addElement(new Node(*candidate));
            }
        }
        delete nearbyNodes;
    }
    // Repeat this backtracking process for each node you add to the path until you reach the start node.”
    // Think carefully the path that you return must be from start to finish, not finish to start.
    // Be aware that the returned path is a deep copy of the path, so you need to return a new NodeList object.


    // reverse list
    NodeList *forwardPath = new NodeList();
    for (int i = backwardPath->getLength(); i > 0; i--)
    {
        Node *node = backwardPath->getNode(i - 1);
        // cout << node->toString() << endl;
        forwardPath->addElement(new Node(*node));
    }
    delete backwardPath;
    return forwardPath;

}

//-----------------------------
NodeList *PathSolver::getNearbyNodes(Node *node)
{
    NodeList *nearbyNodes = new NodeList();
    //up
    nearbyNodes->addElement(new Node(node->getRow() - 1, node->getCol(), node->getDistanceTraveled() + 1));

    //right
    nearbyNodes->addElement(new Node(node->getRow(), node->getCol() + 1, node->getDistanceTraveled() + 1));

    //down
    nearbyNodes->addElement(new Node(node->getRow() + 1, node->getCol(), node->getDistanceTraveled() + 1));

    //left
    nearbyNodes->addElement(new Node(node->getRow(), node->getCol() - 1, node->getDistanceTraveled() + 1));

    return nearbyNodes;
}

NodeList *PathSolver::getNearbyNodes(NodeList *nodeList, Node *node)
{
    NodeList *nearbyNodes = new NodeList();
    for (int i = 0; i < nodeList->getLength(); i++)
    {
        Node *candidate = nodesExplored->getNode(i);

            //if there is a difference of 1 in row and 0 in col, or vice versa, then the candidate node must be adjacent
            
        if ((((abs(candidate->getCol() - node->getCol()) == 1 
        && abs(candidate->getRow() - node->getRow()) == 0)) 
        || ((abs(candidate->getRow() - node->getRow()) == 1 
        && abs(candidate->getCol() - node->getCol()) == 0))))
        {
            nearbyNodes->addElement(new Node(*candidate));
        }
    }
    return nearbyNodes;
}

//helper function to visualise how forwardSearch progresses
void PathSolver::visualiseEnv(Env env, NodeList *P, Node *p)
{
    //change all P to ?'s
    for (int i = 0; i < P->getLength(); i++)
    {
        if (env[P->getNode(i)->getCol()][P->getNode(i)->getRow()] != 'G')
        {
            env[P->getNode(i)->getCol()][P->getNode(i)->getRow()] = '?';
        }
    }

    //change all C to x's
    for (int i = 0; i < nodesExplored->getLength(); i++)
    {
        if (env[nodesExplored->getNode(i)->getCol()][nodesExplored->getNode(i)->getRow()] != 'G')
        {
            env[nodesExplored->getNode(i)->getCol()][nodesExplored->getNode(i)->getRow()] = 'x';
        }
    }

    //change p to #
    if (env[p->getCol()][p->getRow()] != 'G')
    {
        env[p->getCol()][p->getRow()] = '#';
    }

    //print
    for (int i = 0; i < ENV_DIM; i++)
    {
        for (int j = 0; j < ENV_DIM; j++)
        {
            cout << env[i][j];
        }
        cout << endl;
    }
}