//
// Created by Eitan Kats on 11/05/2022.
//

#include "OrgChart.hpp"
#include "OrgChartLevelIterator.hpp"
#include "iostream"
#include "stdexcept"
#include "queue"
#include "OrgChartReverseIterator.hpp"
#include "algorithm"

namespace ariel {
    //region iterator methods
    OrgChartLevelIterator OrgChart::begin() {
        return OrgChartLevelIterator(this->_root);
    }

    OrgChartLevelIterator OrgChart::end() {
        return OrgChartLevelIterator(nullptr);
    }

    OrgChartLevelIterator OrgChart::begin_level_order() {
        return OrgChartLevelIterator(this->_root);
    }

    OrgChartLevelIterator OrgChart::end_level_order() {
        return OrgChartLevelIterator(nullptr);
    }


    OrgChartPreOrderIterator OrgChart::begin_preorder() {
        return OrgChartPreOrderIterator(this->_root);
    }

    OrgChartPreOrderIterator OrgChart::end_preorder() {
        return OrgChartPreOrderIterator(nullptr);
    }

    OrgChartReverseIterator OrgChart::begin_reverse_order() {
        return OrgChartReverseIterator(this->_root);
    }

    OrgChartReverseIterator OrgChart::reverse_order() {
        return OrgChartReverseIterator(nullptr);
    }

    OrgChartReverseIterator OrgChart::end_reverse_order() {
        return OrgChartReverseIterator(nullptr);
    }
    //endregion

    OrgChart::OrgChart() : _root(nullptr) {}

    static void printSubtree(std::ostream &output, const Node *currNode, const std::string &prefix) {
        output << currNode->getLabel() << "\n";
        for (Node *child: currNode->getChildren()) {
            output << prefix << "  |--";
            std::string depthIdent = "";
            for (int i = 0; i < child->getLevel(); ++i) {
                depthIdent += "   ";
            }
            printSubtree(output, child, depthIdent);
        }
    }

    std::ostream &operator<<(std::ostream &output, const OrgChart &chart) {
        if (chart._root != nullptr) {
            printSubtree(output, chart._root, "");
        }
        return output;
    }

    OrgChart &OrgChart::add_root(const std::string &newRoot) {

        if (_root == nullptr) {
            Node *rootNode = new Node(newRoot);
            this->_root = rootNode;
        } else {
            std::string prevLabel = this->_root->getLabel();
            this->_root->setLabel(newRoot);
            this->labelMap.erase(prevLabel);
        }
        this->labelMap.insert({newRoot, this->_root});

        return *this;

    }

    OrgChart &OrgChart::add_sub(const std::string &existingElem, const std::string &newElem) {
        auto searchResult = this->labelMap.find(existingElem);
        if (searchResult != this->labelMap.end()) {
            Node *currNode = searchResult->second;
            Node *newChild = new Node(newElem);
            newChild->setLevel(currNode->getLevel() + 1);
            currNode->add_child(newChild);
            this->labelMap.insert({newElem, newChild});

        } else {
            throw std::invalid_argument("element doesn't exist");
        }
        return *this;
    }

    OrgChart::~OrgChart() {
        this->clearChart();
    }

    OrgChart &OrgChart::operator=(OrgChart &otherChart) {
        OrgChart temp(otherChart);
        std::swap(this->_root, temp._root);
        std::swap(this->labelMap, temp.labelMap);
        return *this;
    }

    OrgChart::OrgChart(const OrgChart &otherChart) : _root(nullptr) {
        if (otherChart._root != nullptr) {
            this->add_root(otherChart._root->getLabel());
            std::queue<Node *> bfsQueue;
            bfsQueue.push(otherChart._root);

            while (!bfsQueue.empty()) {
                Node *toCopy = bfsQueue.front();
                bfsQueue.pop();
                for (Node *child: toCopy->getChildren()) {
                    this->add_sub(toCopy->getLabel(), child->getLabel());
                    bfsQueue.push(child);
                }
            }
        }
    }

    void OrgChart::clearChart() {
        if (_root == nullptr) {
            return;
        }
        std::queue<Node *> clearingQueue;
        for (Node *child: this->_root->getChildren()) {
            clearingQueue.push(child);
        }
        delete this->_root;
        while (!clearingQueue.empty()) {
            Node *toClear = clearingQueue.front();
            clearingQueue.pop();
            for (Node *child: toClear->getChildren()) {
                clearingQueue.push(child);
            }
            delete toClear;
        }
    }

}