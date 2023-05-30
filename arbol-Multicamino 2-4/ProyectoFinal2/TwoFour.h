//
// Created by brian on 1/11/2022.
//

#ifndef PROYECTO2_TWOFOUR_H
#define PROYECTO2_TWOFOUR_H

#include "Node.h"

class TwoFour {
private:
    Node *root;

public:
    TwoFour();


    void insert(int dValue);

    void split(Node *thisNode);

    Node *getNextChild(Node *theNode, int theValue);

    void displayTree(int i);

    void recDisplayTree(Node *thisNode, int level, int childNumber);

    void inorderdisplay(Node *thisNode, int level, int childNumber);

    Node *find(int theValue);

    Node *findvalue(Node *theNode, int theValue);

    Node *deletes(Node *currnode, int theValue);

    Node *deleteleaf_cases(Node *thisNode, int theValue);

    Node *balancetree(Node *currnode);

    Node *getinordernode(Node *thisNode);

    virtual ~TwoFour();
};


#endif //PROYECTO2_TWOFOUR_H
