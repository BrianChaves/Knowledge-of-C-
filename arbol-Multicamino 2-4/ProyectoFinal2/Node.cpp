//
// Created by brian on 1/11/2022.
//

#include "Node.h"

Node::Node() {
    numItems = 0;
    for (int i = 0; i < ORDER; i++)
        childArray[i] = nullptr;
    for (int i = 0; i < ORDER - 1; i++)
        itemArray[i] = nullptr;

}


int Node::getNumItems() const {
    return numItems;
}


Node *Node::getParent() const {
    return parent;
}


void Node::connectChild(int childNum, Node *child) {
    childArray[childNum] = child;
    if (child != nullptr)
        child->parent = this;
}


Node *Node::disconnectChild(int childNum) {
    Node *tempNode = childArray[childNum];
    childArray[childNum] = nullptr;
    return tempNode;
}


Node *Node::getChild(int childNum) {
    return childArray[childNum];
}

bool Node::isLeaf() {
    return (childArray[0] == nullptr) ? true : false;
}


NodeData *Node::getItem(int index) // get NodeData at index
{
    return itemArray[index];
}


NodeData *Node::setItem(int index, NodeData *theValue) // get NodeData at index
{
    itemArray[index] = theValue;
    return itemArray[index];
}


bool Node::isFull() {
    return (numItems == ORDER - 1) ? true : false;
}


int Node::insertItem(NodeData *newItem) {
    numItems++; // will add new item
    int newKey = newItem->getDData();
    for (int j = ORDER - 2; j >= 0; j--) // start on right,
    { // examine items

        if (itemArray[j] == nullptr) // if item null,
            continue; // go left one cell
        else // not null,
        { // get its key
            int itsKey = itemArray[j]->getDData();
            if (newKey < itsKey) // if it's bigger
                itemArray[j + 1] = itemArray[j]; // shift it right
            else {
                itemArray[j + 1] = newItem; // insert new item
                return j + 1; // return index to
            } // new item
        } // end else (not null)
    } // end for // shifted all items,
    itemArray[0] = newItem; // insert new item
    return 0;
} // end insertItem()


void Node::insertatfront(NodeData *newItem) {

    int newKey = newItem->getDData();
    numItems++;
    for (int j = numItems - 1; j > 0; j--) {
        itemArray[j] = itemArray[j - 1];
        connectChild(j + 1, disconnectChild(j));
    }
    connectChild(1, disconnectChild(0));
    itemArray[0] = newItem;
    connectChild(0, nullptr);

    return;
}

NodeData *Node::removeItem() {
    // assumes node not empty
    NodeData *temp = itemArray[numItems - 1]; // save item
    itemArray[numItems - 1] = nullptr; // disconnect it
    numItems--; // one less item
    return temp; // return item
}

void Node::displayNode() {
    for (int j = 0; j < numItems; j++)
        itemArray[j]->displayItem(); // "56,"
}

void Node::displayvalue(int j) { // format "/24/56/74/"
    itemArray[j]->displayItem(); // "/56"


}


void Node::deletenodevalue(int theValue) {
    int flag = -1;
    // just delete the value and decrease node size
    for (int i = 0; i < numItems; i++) {
        if (theValue == itemArray[i]->getDData()) {
            flag = i;
        }
        if (flag != -1 && i + 1 < numItems) {
            itemArray[i]->setDData(itemArray[i + 1]->getDData());// = itemArray[i + 1].getDData();

        }
    }
    itemArray[numItems - 1] = nullptr; // disconnect it
    numItems--; // one less item
}


void Node::deletevalue(int theValue, string side) {
    // Only valid for leafs
    int flag = -1;
    // just delete the value and decrease node size
    for (int i = 0; i < numItems; i++) {
        if (theValue == itemArray[i]->getDData()) {
            flag = i;
        }
        if (flag != -1 && i + 1 < numItems) {
            itemArray[i]->setDData(itemArray[i + 1]->getDData());//= itemArray[i + 1].getDData();
        }
    }
    itemArray[numItems - 1] = nullptr; // disconnect it
    numItems--; // one less item
}


Node *Node::getsibiling(int theValue) {

// get the sibling
    Node *x = nullptr;
    Node p = *getParent();
    if (numItems != 0) {
        for (int i = 0; i <= p.numItems; i++) {
            if (p.childArray[i]->itemArray[0]->getDData() < theValue) {
                x = p.childArray[i];
            }
        }
    } else if (numItems == 0) {
        for (int i = 0; i <= p.numItems; i++) {
            if (p.childArray[i]->itemArray[0] == nullptr) {

                if (i != 0) {
                    x = p.childArray[i - 1];
                }
            }
        }
    }
    return x;
}


Node::~Node() {

}

void Node::setParent(Node *parent) {
    this->parent = parent;
}

void Node::setNumItems(int theValue) {
    numItems = theValue;
    return;
}

