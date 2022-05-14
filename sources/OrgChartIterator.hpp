//
// Created by Eitan Kats on 14/05/2022.
//

#ifndef EX5_CPP_ORGCHARTITERATOR_HPP
#define EX5_CPP_ORGCHARTITERATOR_HPP

#include "Node.hpp"


namespace ariel {
    class OrgChartIterator {
        using valueType = Node *;
        using reference = Node &;
    protected:

        valueType _ptr;

        OrgChartIterator(valueType ptr);

    public:

        reference operator*() const { return *_ptr; }

        valueType operator->() { return _ptr; }

        bool operator==(const OrgChartIterator &b) const;

        bool operator!=(const OrgChartIterator &b) const;
    };
}


#endif //EX5_CPP_ORGCHARTITERATOR_HPP
