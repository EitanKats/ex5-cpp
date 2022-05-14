//
// Created by Eitan Kats on 11/05/2022.
//

#include "OrgChart.hpp"
#include "OrgChartLevelIterator.hpp"
#include "iostream"
#include "stdexcept"
#include "queue"

namespace ariel {
//    OrgChart::Iterator OrgChart::begin() {
//        return Iterator(&(this->_root));
//    }
//
//    OrgChart::Iterator OrgChart::end() {
//        return Iterator(nullptr);
//    }

    OrgChartLevelIterator OrgChart::begin_level_order() {
        return OrgChartLevelIterator(this->_root);
    }

    OrgChartLevelIterator OrgChart::end_level_order() {
        return OrgChartLevelIterator(nullptr);
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

    OrgChart::~OrgChart() {
        this->clearChart();
    }

    OrgChart &OrgChart::operator=(OrgChart &otherChart) {
        return *this;
    }

    OrgChart::OrgChart(const OrgChart &otherChart) {

    }

    void OrgChart::clearChart() {
        std::queue<Node *> clearingQueue;
        for (Node *child: this->_root->getChildren()) {
            clearingQueue.push(child);
        }
        delete this->_root;
        while (!clearingQueue.empty()) {
            Node *toClear = clearingQueue.front();
            clearingQueue.pop();
            std::cout << " \n CLEARING: " << toClear->getLabel() << std::endl;
            for (Node *child: toClear->getChildren()) {
                clearingQueue.push(child);
            }
            delete toClear;
        }
    }

}