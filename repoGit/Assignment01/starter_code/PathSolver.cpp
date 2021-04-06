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

    NodeList *openList = new NodeList();
    openList->addElement(start);
    Node *p = start;

    //LOOP:
    int i = 1; //remove after testing
    while (env[p->getCol()][p->getRow()] != 'G' &&
           !equals(openList, nodesExplored))
    // for (int loopnum = 0; loopnum < 20; loopnum++)
    {
        i++; //remove after testing

        // Let C be a list of positions the that has already being explored, with distances (initially empty). This is also called the closed-list.
        //*** this list is nodesExplored.
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

            if ((p->getEstimatedDist2Goal(goal) - p->getDistanceTraveled() >= (candidateNode->getEstimatedDist2Goal(goal) - candidateNode->getDistanceTraveled())) &&
                !nodesExplored->doesContain(candidateNode))
            {
                // cout << "old p: " << p->toString();
                // cout << ". Est. distance to goal: " << p->getEstimatedDist2Goal(goal) - p->getDistanceTraveled() << endl;
                p = candidateNode;
                // cout << "new p: " << p->toString();
                // cout << ". Est. distance to goal: " << p->getEstimatedDist2Goal(goal) - p->getDistanceTraveled() << endl;
            }
            // if (i + 1 == openList->getLength())
            // {
            //     for (int j = 0; j < openList->getLength() && nodesExplored->doesContain(p); j++)
            //     {
            //         p = openList->getNode(j);
            //     }
            // }
        }

        // for Each position q in Env that the robot can reach from p do
        // Set the distance_travelled of q to be one more that that of p
        // Add q to open-list P only if it is not already in it.

        addNearbytoP(env, openList, p);
        // end

        // cout << openList->toString() << endl;

        // Add p to closed-list C.

        //TODO  maybe? change this from a deep to a shallow copy. must resolve issue of deconstuctor of both lists trying to delete a node that has already been deleted by the other deconstructor.
        nodesExplored->addElement(new Node(p->getRow(), p->getCol(), p->getDistanceTraveled()));

        visualiseEnv(env, openList, p);
        cout << endl;

        //TODO get acccurate distance travelled after jumping backwards
    }

    // until The robot reaches the goal, that is, p == G, or no such position p can be found
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
    return new NodeList(*nodesExplored);
}

NodeList *PathSolver::getPath(Env env)
{
    // TODO
    return nullptr;
}

//-----------------------------

void PathSolver::addNearbytoP(Env env, NodeList *openList, Node *p)
{
    //up
    int row = p->getRow();
    int col = p->getCol() - 1;
    int dist_traveled = p->getDistanceTraveled();

    if (!openList->doesContain(new Node(row, col, dist_traveled)) && (env[col][row] == '.' || env[col][row] == 'G'))
    {
        openList->addElement(new Node(row, col, dist_traveled + 1));
    }
    //right
    row++;
    col++;
    if (!openList->doesContain(new Node(row, col, dist_traveled)) && (env[col][row] == '.' || env[col][row] == 'G'))
    {
        openList->addElement(new Node(row, col, dist_traveled + 1));
    }
    //down
    row--;
    col++;
    if (!openList->doesContain(new Node(row, col, dist_traveled)) && (env[col][row] == '.' || env[col][row] == 'G'))
    {
        openList->addElement(new Node(row, col, dist_traveled + 1));
    }

    //left
    row--;
    col--;
    if (!openList->doesContain(new Node(row, col, dist_traveled)) && (env[col][row] == '.' || env[col][row] == 'G'))
    {
        openList->addElement(new Node(row, col, dist_traveled + 1));
    }
}

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

bool PathSolver::equals(NodeList *list1, NodeList *list2)
{
    bool equals = true;
    for (int i = 0; i < list1->getLength(); i++)
    {
        if (!list2->doesContain(list1->getNode(i)))
        {
            equals = false;
        }
    }

    return equals;
}
