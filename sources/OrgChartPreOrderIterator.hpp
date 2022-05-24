//
// Created by Eitan Kats on 14/05/2022.
//

#ifndef EX5_CPP_ORGCHARTPREORDERITERATOR_HPP
#define EX5_CPP_ORGCHARTPREORDERITERATOR_HPP

#include "stack"
#include "Node.hpp"
#include "OrgChartIterator.hpp"

namespace ariel {
    class OrgChartPreOrderIterator : public OrgChartIterator {

    private:

        std::stack<Node *> currStack;

        void push_node_children();

    public:
        OrgChartPreOrderIterator(Node *ptr);

        OrgChartPreOrderIterator &operator++() override;

        OrgChartPreOrderIterator operator++(int);
    };
}


#endif //EX5_CPP_ORGCHARTPREORDERITERATOR_HPP
