#include "NodeList.h"
#include <iostream>

NodeList::NodeList()
{
    length = 0;
}

NodeList::~NodeList()
{
    for (int i = 0; i < length; i++)
    {
        delete nodes[i];
    }
}

NodeList::NodeList(NodeList &other)
{ //Completed
    this->length = other.length;

    for (int i=0;i<length;i++){
        Node *old = other.nodes[i];

        nodes[i] = new Node(old->getRow(),old->getCol(),old->getDistanceTraveled());
    }
}

int NodeList::getLength()
{ //Completed
    return length;
}

void NodeList::addElement(Node *newPos)
{
    // completed
    if (newPos != nullptr && length < NODE_LIST_ARRAY_MAX_SIZE)
    {
        nodes[length] = newPos;
        length++;
    }
}

Node *NodeList::getNode(int i)
{ //completed
    Node * node = nullptr;
    if (nodes != nullptr && nodes[i] != nullptr){
        node = nodes[i];
    }
    return node;
}