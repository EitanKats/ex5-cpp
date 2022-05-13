//
// Created by Eitan Kats on 11/05/2022.
//

#include "OrgChart.hpp"
#include "OrgChartIterator.hpp"
#include "iostream"
#include "stdexcept"

namespace ariel {
//    OrgChart::Iterator OrgChart::begin() {
//        return Iterator(&(this->_root));
//    }
//
//    OrgChart::Iterator OrgChart::end() {
//        return Iterator(nullptr);
//    }

    OrgChartIterator OrgChart::begin_level_order() {
        return OrgChartIterator(this->_root);
    }

    OrgChartIterator OrgChart::end_level_order() {
        return OrgChartIterator(nullptr);
    }

//    Iterator OrgChart::begin_reverse_order();
//
//    Iterator OrgChart::begin_preorder();
//
//    Iterator OrgChart::end_preorder();

    OrgChart::OrgChart() {}

    OrgChart::OrgChart(const Node *root) {
        this->labelMap.insert({root->getLabel(), this->_root});
    }

    std::ostream &operator<<(std::ostream &output, const OrgChart &chart) {
        output << "BLA";
        return output;
    }

    OrgChart &OrgChart::add_root(const std::string &newRoot) {
        Node *rootNode = new Node(newRoot);
        this->_root = rootNode;
        this->labelMap.insert({newRoot, this->_root});
        return *this;
    }

    OrgChart &OrgChart::add_sub(const std::string &existingElem, const std::string &newElem) {
        auto searchResult = this->labelMap.find(existingElem);
        if (searchResult != this->labelMap.end()) {
            Node *currNode = searchResult->second;
            Node *newChild = new Node(newElem);
            currNode->add_child(newChild);
            this->labelMap.insert({newElem, newChild});

        } else {
            throw std::invalid_argument("element doesn't exist");
        }
        // check whether the existing element exists
        // check what is the type of the first element
        return *this;
    }

}