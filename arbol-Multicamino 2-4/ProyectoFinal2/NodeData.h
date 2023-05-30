//
// Created by brian on 1/11/2022.
//

#ifndef PROYECTO2_NODEDATA_H
#define PROYECTO2_NODEDATA_H

#include <iostream>
#include <sstream>

using namespace std;

class NodeData {
    int dData;
public:
    NodeData();

    NodeData(int dData);

    int getDData() const;

    void setDData(int dData);

    void displayItem();
};


#endif //PROYECTO2_NODEDATA_H
