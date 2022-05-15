//
// Created by Eitan Kats on 14/05/2022.
//

#include "OrgChartPreOrderIterator.hpp"
#include "OrgChartIterator.hpp"

namespace ariel {

    void OrgChartPreOrderIterator::push_node_children() {
        if (!_ptr->getChildren().empty()) {
            const std::vector<Node *> children = _ptr->getChildren();
            auto _reverse_start = children.crbegin();
            auto _reverse_end = children.crend();
            for (; _reverse_start != _reverse_end; ++_reverse_start) {
                currStack.push(*_reverse_start);
            }
        }
    }

    OrgChartPreOrderIterator::OrgChartPreOrderIterator(valueType ptr) : OrgChartIterator(ptr) {
        if (ptr != nullptr) {
            this->push_node_children();
        }
    }

    OrgChartPreOrderIterator &OrgChartPreOrderIterator::operator++() {
        if (!currStack.empty()) {
            _ptr = currStack.top();
            currStack.pop();
            this->push_node_children();
        } else {
            _ptr = nullptr;
        }

        return *this;
    }
}