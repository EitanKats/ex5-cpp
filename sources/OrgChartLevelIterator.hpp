//
// Created by Eitan Kats on 12/05/2022.
//

#ifndef EX5_CPP_ORGCHARTLEVELITERATOR_HPP
#define EX5_CPP_ORGCHARTLEVELITERATOR_HPP

#include "Node.hpp"
#include "queue"
#include "OrgChartIterator.hpp"

namespace ariel {
    class OrgChartLevelIterator : public OrgChartIterator {

    private:
        std::queue<Node *> currQueue;

        void push_node_children();

    public:
        OrgChartLevelIterator(Node * ptr);

        // Prefix increment
        OrgChartLevelIterator &operator++() override;

        // Postfix increment
        OrgChartLevelIterator operator++(int);

    };
}


#endif //EX5_CPP_ORGCHARTLEVELITERATOR_HPP
