//
// Created by Eitan Kats on 15/05/2022.
//

#ifndef EX5_CPP_ORGCHARTREVERSEITERATOR_HPP
#define EX5_CPP_ORGCHARTREVERSEITERATOR_HPP

#include "Node.hpp"
#include "stack"
#include "queue"
#include "OrgChartIterator.hpp"

namespace ariel {
    class OrgChartReverseIterator : public OrgChartIterator {

    private:
        std::stack<Node *> currStack;
        std::queue<Node *> currQueue;

        void push_node_children(Node *);

    public:
        OrgChartReverseIterator(Node * ptr);

        OrgChartReverseIterator &operator++() override;

        OrgChartReverseIterator operator++(int);
    };
}


#endif //EX5_CPP_ORGCHARTREVERSEITERATOR_HPP
