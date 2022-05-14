//
// Created by Eitan Kats on 14/05/2022.
//

#include "OrgChartPreOrderIterator.hpp"
#include "OrgChartIterator.hpp"

namespace ariel {

    void OrgChartPreOrderIterator::push_node_children() {
        if (!_ptr->getChildren().empty()) {
            _ptr->getChildren();
            for (valueType child: _ptr->getChildren()) {
                currQueue.push(child);
            }
        }
    }

    OrgChartPreOrderIterator::OrgChartPreOrderIterator(valueType ptr) : OrgChartIterator(ptr) {
        if (ptr != nullptr) {
            this->push_node_children();
        }
    }

    OrgChartPreOrderIterator &OrgChartPreOrderIterator::operator++() {
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