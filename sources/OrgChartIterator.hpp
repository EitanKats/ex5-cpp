//
// Created by Eitan Kats on 14/05/2022.
//

#ifndef EX5_CPP_ORGCHARTITERATOR_HPP
#define EX5_CPP_ORGCHARTITERATOR_HPP

#include "Node.hpp"
// code based on:
//https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp

namespace ariel {
    class OrgChartIterator {

    private:

        Node *_ptr;

    protected:

        OrgChartIterator(Node *ptr);

    public:

        const Node *getPtr() const;

        void setPtr(Node *ptr);

        const std::string &operator*() const;

        const std::string *operator->();

        bool operator==(const OrgChartIterator &b) const;

        bool operator!=(const OrgChartIterator &b) const;

        virtual OrgChartIterator &operator++() = 0;
    };
}


#endif //EX5_CPP_ORGCHARTITERATOR_HPP
