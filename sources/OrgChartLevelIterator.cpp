//
// Created by Eitan Kats on 14/05/2022.
//
#include "OrgChartLevelIterator.hpp"
#include "OrgChartIterator.hpp"

namespace ariel {
    void OrgChartLevelIterator::push_node_children() {
        if (!getPtr()->getChildren().empty()) {
            for (Node * child: getPtr()->getChildren()) {
                currQueue.push(child);
            }
        }
    }

    OrgChartLevelIterator::OrgChartLevelIterator(Node * ptr) : OrgChartIterator(ptr) {
        if (ptr != nullptr) {
            this->push_node_children();
        }
    }

    OrgChartLevelIterator &OrgChartLevelIterator::operator++() {
        if (!currQueue.empty()) {

            setPtr(currQueue.front());
            currQueue.pop();
            this->push_node_children();
        } else {
            setPtr(nullptr);
        }

        return *this;
    }

    OrgChartLevelIterator OrgChartLevelIterator::operator++(int) {
        OrgChartLevelIterator tmp = *this;
        ++(*this);
        return tmp;
    }
}
