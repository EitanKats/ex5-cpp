//
// Created by Eitan Kats on 14/05/2022.
//

#include "OrgChartIterator.hpp"

namespace ariel {

    OrgChartIterator::OrgChartIterator(valueType ptr) : _ptr(ptr) {

    }

    bool OrgChartIterator::operator==(const OrgChartIterator &b) const{
        return this->_ptr == b._ptr;
    }

    bool OrgChartIterator::operator!=(const OrgChartIterator &b) const{
        return this->_ptr != b._ptr;
    }
}
