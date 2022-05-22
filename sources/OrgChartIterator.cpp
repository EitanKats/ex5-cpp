//
// Created by Eitan Kats on 14/05/2022.
//

#include "OrgChartIterator.hpp"

namespace ariel {

    bool OrgChartIterator::operator!=(const OrgChartIterator &b) const {
        return this->_ptr != b._ptr;
    }

    bool OrgChartIterator::operator==(const OrgChartIterator &b) const {
        return this->_ptr == b._ptr;
    }

    const std::string *OrgChartIterator::operator->() {
        return &(_ptr->getLabel());
    }

    const std::string &OrgChartIterator::operator*() const {
        return (*_ptr).getLabel();
    }

    void OrgChartIterator::setPtr(Node *ptr) {
        _ptr = ptr;
    }

    const Node *OrgChartIterator::getPtr() const {
        return _ptr;
    }

    OrgChartIterator::OrgChartIterator(Node *ptr) : _ptr(ptr) {

    }
}
