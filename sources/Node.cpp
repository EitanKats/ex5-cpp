//
// Created by Eitan Kats on 11/05/2022.
//

#include "Node.hpp"
#include "iostream"
#include "cctype"
#include "stdexcept"

namespace ariel {

    Node::Node(const std::string &label) : _label(label), _level(0) {
        validateNodeString(label);
    }

    Node::Node() {}


    std::ostream &operator<<(std::ostream &output, const Node &currNode) {
        output << currNode._label;
        return output;
    }

    const std::vector<Node *> &Node::getChildren() const {
        return _children;
    }

    const std::string &Node::getLabel() const {
        return _label;
    }

    void Node::add_child(Node *newChild) {
        this->_children.push_back(newChild);
    }

    void Node::setLabel(const std::string &label) {
        validateNodeString(label);
        _label = label;
    }

    void Node::setLevel(int level) {
        _level = level;
    }

    int Node::getLevel() const {
        return _level;
    }

    void Node::validateNodeString(const std::string &label) const {
        for (const char &currC: label) {
            if (!std::isprint(currC)) { throw std::runtime_error("Illegal character"); }
        }
    }

}