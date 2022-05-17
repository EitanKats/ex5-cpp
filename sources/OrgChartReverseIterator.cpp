//
// Created by Eitan Kats on 15/05/2022.
//

#include "OrgChartReverseIterator.hpp"

namespace ariel {
    void OrgChartReverseIterator::push_node_children() {
        if (!_ptr->getChildren().empty()) {
            _ptr->getChildren();
            for (valueType child: _ptr->getChildren()) {
                currQueue.push(child);
            }
        }
    }

    OrgChartReverseIterator::OrgChartReverseIterator(valueType ptr) : OrgChartIterator(ptr) {
        if (ptr != nullptr) {
            this->push_node_children();
        }
    }

    OrgChartReverseIterator &OrgChartReverseIterator::operator++() {
        if (!currQueue.empty()) {
            _ptr = currQueue.top();
            currQueue.pop();
            this->push_node_children();
        } else {
            _ptr = nullptr;
        }

        return *this;
    }

}