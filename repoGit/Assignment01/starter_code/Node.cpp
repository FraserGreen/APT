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
    // TODO
}

int Node::getRow()
{ //completed
    return row;
}

int Node::getCol()
{ //completed
    return col;
}

int Node::getDistanceTraveled()
{ //completed
    return dist_traveled;
}

void Node::setDistanceTraveled(int dist_traveled)
{ //completed
    this->dist_traveled = dist_traveled;
}

int Node::getEstimatedDist2Goal(Node *goal)
{ //completed
    // returns manhattan distance between current node and goal node
    return dist_traveled + (abs(col - goal->col) + abs(row - goal->row));
}

//--------------------------------

std::string Node::toString()
{
    std::string str;
    str.append("Row: ");
    str.append(std::to_string(row));
    str.append(", Column: ");
    str.append(std::to_string(col));
    str.append(", Distance Travelled: ");
    str.append(std::to_string(dist_traveled));
    return str;
}
