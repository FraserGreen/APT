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
{ 
    this->length = other.length;

    for (int i = 0; i < length; i++)
    {
        Node *old = other.nodes[i];

        nodes[i] = new Node(old->getRow(), old->getCol(), old->getDistanceTraveled());
    }
}

int NodeList::getLength()
{ 
    return length;
}

void NodeList::addElement(Node *newPos)
{
    if (newPos != nullptr && length < NODE_LIST_ARRAY_MAX_SIZE)
    {
        nodes[length] = newPos;
        length++;
    }
}

Node *NodeList::getNode(int i)
{ 
    Node *node = nullptr;
    if (nodes != nullptr && nodes[i] != nullptr)
    {
        node = nodes[i];
    }
    return node;
}


bool NodeList::doesContain(Node *node)
{
    bool isInList = false;
    for (int i = 0; node != nullptr && i < length; i++)
    {
        if (node->getRow() == nodes[i]->getRow() &&
            node->getCol() == nodes[i]->getCol())
        {
            isInList = true;
        }
    }
    return isInList;
}

bool NodeList::isSupersetOf(NodeList *smallerList)
{
    bool equals = true;
    for (int i = 0; i < length; i++)
    {
        if (!smallerList->doesContain(nodes[i]))
        {
            equals = false;
        }
    }

    return equals;
}