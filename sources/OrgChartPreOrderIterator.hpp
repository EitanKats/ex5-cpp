//
// Created by Eitan Kats on 14/05/2022.
//

#ifndef EX5_CPP_ORGCHARTPREORDERITERATOR_HPP
#define EX5_CPP_ORGCHARTPREORDERITERATOR_HPP

#include "queue"
#include "Node.hpp"
#include "OrgChartIterator.hpp"

namespace ariel {
    class OrgChartPreOrderIterator : public OrgChartIterator {
        using valueType = Node *;
        using reference = Node &;
    private:
        std::queue<valueType> currQueue;

        void push_node_children();

    public:
        OrgChartPreOrderIterator(valueType ptr);

        OrgChartPreOrderIterator &operator++();
    };
}


#endif //EX5_CPP_ORGCHARTPREORDERITERATOR_HPP
