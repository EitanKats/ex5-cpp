//
// Created by Eitan Kats on 14/05/2022.
//
#include "OrgChartLevelIterator.hpp"
#include "OrgChartIterator.hpp"

namespace ariel {
    void OrgChartLevelIterator::push_node_children() {
        if (!_ptr->getChildren().empty()) {
            _ptr->getChildren();
            for (valueType child: _ptr->getChildren()) {
                currQueue.push(child);
            }
        }
    }

    OrgChartLevelIterator::OrgChartLevelIterator(valueType ptr) : OrgChartIterator(ptr) {
        if (ptr != nullptr) {
            this->push_node_children();
        }
    }

    OrgChartLevelIterator &OrgChartLevelIterator::operator++() {
        if (!currQueue.empty()) {
            _ptr = currQueue.front();
            currQueue.pop();
            this->push_node_children();
        } else {
            _ptr = nullptr;
        }

        return *this;
    }
}
