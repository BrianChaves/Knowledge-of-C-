//
// Created by brian on 1/11/2022.
//

#ifndef PROYECTO2_NODE_H
#define PROYECTO2_NODE_H

#include <iostream>
#include <sstream>
#include "NodeData.h"
#include <vector>

using namespace std;

class Node {
private:
    const int ORDER = 4;

    int numItems;
    Node *parent;
    Node **childArray = new Node *[ORDER];
    NodeData **itemArray = new NodeData *[ORDER - 1];
public:

    Node();


    int getNumItems() const;

    void setNumItems(int numItems);

    Node *getParent() const;

    void setParent(Node *parent);


    void connectChild(int childNum, Node *child);

    Node *disconnectChild(int childNum);

    Node *getChild(int childNum);

    bool isLeaf();

    NodeData *getItem(int index);

    NodeData *setItem(int index, NodeData *theValue);

    bool isFull();

    int insertItem(NodeData *newItem);

    void insertatfront(NodeData *newItem);

    NodeData *removeItem();

    void displayNode();

    void displayvalue(int j);


    void deletenodevalue(int theValue);


    void deletevalue(int theValue, string side);


    Node *getsibiling(int theValue);

    virtual ~Node();
};


#endif //PROYECTO2_NODE_H
