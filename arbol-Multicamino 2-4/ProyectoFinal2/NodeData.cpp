//
// Created by brian on 1/11/2022.
//

#include "NodeData.h"

NodeData::NodeData(int dData) : dData(dData) {}

void NodeData::displayItem() {
    cout << getDData() << ",";
}
NodeData::NodeData() {
    dData=0;
}

int NodeData::getDData() const {
    return dData;
}

void NodeData::setDData(int dData) {
    NodeData::dData = dData;
}

