//
// Created by Eitan Kats on 12/05/2022.
//

#ifndef EX5_CPP_ORGCHARTITERATOR_HPP
#define EX5_CPP_ORGCHARTITERATOR_HPP

#include "OrgChart.hpp"
#include "Node.hpp"
#include "queue"

namespace ariel {
    class OrgChartIterator {
        using valueType = Node*;
        using reference = Node &;

    private:
        std::queue<valueType> currQueue;
        valueType _ptr;

        void push_node_children() {
            if (!_ptr->getChildren().empty()) {
                _ptr->getChildren();
                for (valueType child: _ptr->getChildren()) {
                    currQueue.push(child);
                }
            }
        }

    public:
        OrgChartIterator(valueType ptr) : _ptr(ptr) {
            if (ptr != nullptr) {
                this->push_node_children();
            }

        };

        reference operator*() const { return *_ptr; }

        valueType operator->() { return _ptr; }

        // Prefix increment
        OrgChartIterator &operator++() {
            if (!currQueue.empty()) {
                _ptr = currQueue.front();
                currQueue.pop();
                this->push_node_children();
            } else {
                _ptr = nullptr;
            }

            return *this;
        }

        // Postfix increment
        OrgChartIterator operator++(int) {
            OrgChartIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const OrgChartIterator &a, const OrgChartIterator &b) { return a._ptr == b._ptr; };

        friend bool operator!=(const OrgChartIterator &a, const OrgChartIterator &b) { return a._ptr != b._ptr; };

    };
}


#endif //EX5_CPP_ORGCHARTITERATOR_HPP
