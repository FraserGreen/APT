#include "Node.h"
#include <iostream>

Node::Node(int row, int col, int dist_traveled)
{
    this->row = row;
    this->col = col;
    this->dist_traveled = dist_traveled;
}

Node::~Node()
{
    //intentionally left blank
}

int Node::getRow()
{ 
    return row;
}

int Node::getCol()
{ 
    return col;
}

int Node::getDistanceTraveled()
{ 
    return dist_traveled;
}

void Node::setDistanceTraveled(int dist_traveled)
{ 
    this->dist_traveled = dist_traveled;
}

int Node::getEstimatedDist2Goal(Node *goal)
{ 
    // returns distance traveled + manhattan distance between current node and goal node
    return dist_traveled + (abs(col - goal->col) + abs(row - goal->row));
}

//--------------------------------

Node::Node(Node& other){
    row = other.getRow();
    col = other.getCol();
    dist_traveled = other.getDistanceTraveled();
}
