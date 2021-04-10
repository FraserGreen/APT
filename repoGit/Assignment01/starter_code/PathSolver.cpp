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
    Node *p = get(env, 'S');
    // Input: G- goal location for the robot to get reach
    Node *goal = get(env, 'G'); //TODO may need to change dist_travelled in this node
    // Let P be a list of positions the robot can reach, with distances (initially contains S). This is also called the open-list.

    NodeList *openList = new NodeList();
    openList->addElement(p);
    // Node *p = start;

    //LOOP:
    while (env[p->getCol()][p->getRow()] != 'G' &&
           !equals(openList, nodesExplored))
    // for (int loopnum = 0; loopnum < 20; loopnum++)
    {
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

        //TODO remove openList from this method, do checks inside here
        addNearbytoP(env, openList, p);
        // end

        // cout << openList->toString() << endl;

        // Add p to closed-list C.

        //TODO  maybe? change this from a deep to a shallow copy. must resolve issue of deconstuctor of both lists trying to delete a node that has already been deleted by the other deconstructor.
        nodesExplored->addElement(new Node(p->getRow(), p->getCol(), p->getDistanceTraveled()));

        // visualiseEnv(env, openList, p);

        //TODO get acccurate distance travelled after jumping backwards
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
    // TODO
    Node *goal = nodesExplored->getNode(nodesExplored->getLength() - 1);
    NodeList *path = new NodeList;
    // Hint: “Start from the goal node in the list nodesExplored.  This would be your final element of the path.
    path->addElement(goal);
    // Then search for the the four neighbours of the goal node in nodesExplored. If there is a neighbour that has distance_traveled one less than the goal node. Then that should be the node in the path before the goal node.
    
    while (!path->doesContain(get(env, 'S')))
    {
        Node *currentNode = path->getNode(path->getLength() - 1);

        for (int j = 0; j < nodesExplored->getLength(); j++)
        {
            Node *candidate = nodesExplored->getNode(j);
            // cout << "candidate " << j << ": " << candidate->toString() << endl;
            if ((((abs(candidate->getCol() - currentNode->getCol()) == 1 && abs(candidate->getRow() - currentNode->getRow()) == 0)) || ((abs(candidate->getRow() - currentNode->getRow()) == 1 && abs(candidate->getCol() - currentNode->getCol()) == 0)))&& !path->doesContain(candidate))
            {
                path->addElement(candidate);
                // cout << "candidate successful!" << endl;
            }
        }
    }
    // Repeat this backtracking process for each node you add to the path until you reach the start node.”
    // Think carefully the path that you return must be from start to finish, not finish to start.
    // Be aware that the returned path is a deep copy of the path, so you need to return a new NodeList object.

    //TODO swap values in array (like in previous labwork), and return.
    return nullptr;
}

//-----------------------------

void PathSolver::addNearbytoP(Env env, NodeList *openList, Node *p)
{
    //up
    int row = p->getRow();
    int col = p->getCol() - 1;                        //-1 so it can start looking up straight away.
    int dist_traveled = p->getDistanceTraveled() + 1; //+ 1 because moving will always only move by 1 space.

    int numDirections = 4; //up, right, down, left
    int right = 0;
    int down = 1; //these 3 are used to check against i in the loop later on
    int left = 2;

    //kind of ugly, but not sure how else to do it.
    //firstly it looks to the node above the p, and checks if there it can go there (no wall). If so it adds it to openList (if it is not already there). then it does the same for right, down, and left.
    for (int i = 0; i < numDirections; i++)
    {
        Node *possibleAddition = new Node(row, col, dist_traveled);
        if (!openList->doesContain(possibleAddition) && (env[col][row] == '.' || env[col][row] == 'G'))
        {
            openList->addElement(possibleAddition);
        }
        else
        {
            delete possibleAddition;
        }
        if (i == right)
        {
            row++;
            col++;
        }
        else if (i == down)
        {
            row--;
            col++;
        }
        else if (i == left)
        {
            row--;
            col--;
        }
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
